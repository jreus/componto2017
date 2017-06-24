 /*
 * Graphite Interface
 * 
 * This program visualizes the values coming in from the two 
 * graphite electrodes as bars on the TFT screen.
 * 
 * Hardware:
 * Four electrodes dividing up a graphite drawing.
 * The outermost electrodes go to +5V and Ground
 * The inner two to A0 and A2
 * 
 * Digital Pins connect to the TFT display 
 * as shown in this guide: https://www.arduino.cc/en/Guide/TFTtoBoards
 * 
 * LCD    Arduino
 * +5V      +5V
 * MISO     pin 12
 * SCK      pin 13
 * MOSI     pin 11
 * LCD CS   pin 10
 * SD CS    pin 4
 * D/C      pin 9
 * RESET    pin 8
 * BL       +5V
 * GND      GND
 * 
 * Reference for the TFT library: 
 * https://www.arduino.cc/en/Reference/TFTLibrary
 * 
 * Source code for the TFT library:
 * https://github.com/arduino-libraries/TFT
 * 
 * And in case you're wondering how itoa() works
 * https://playground.arduino.cc/Code/PrintingNumbers
 * http://www.cplusplus.com/reference/cstdlib/itoa/
 * http://www.geeksforgeeks.org/implement-itoa/
 * 
 * 

Given an integer, e.g. 123
    1. divide by 10 => 123/10. Yielding, result = 12 and remainder = 3
    2. add 0x30 to 3 and push on stack (adding 0x30 will convert 3 to ASCII representation)
    3. repeat step 1 until result < 10
    4. add 0x30 to result and store on stack
the stack contains the number in order of | 1 | 2 | 3 | ...

 * 
 * Inspired by "Ground", by Dewi de Vree and Jeroen Uyttendaele
 *
 *  
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 */

#include <arduino.h>
#include <SD.h>
#include <SPI.h>
#include <TFT.h>
#include <stdlib.h>

// SPI pins and other necessary pins to control the TFT screen.
#define SD_CS   4    // SD chip select
#define LCD_CS  10
#define DC      9
#define RST     8

// Graphite electrode pins, use macros in case we want to change them
#define E1 A0
#define E2 A1

#define BAR1_Y 50
#define BAR2_Y 60
#define SCREENWIDTH 160
#define SCREENHEIGHT 128


int main() {
  init();

  TFT myscreen = TFT(LCD_CS, DC, RST);

  myscreen.begin();
  myscreen.background(255,255,255); // black background
  myscreen.noStroke(); // no strokes on rectangles

  int width1, width2;

  while(true) {
    width1 = map(analogRead(E1), 0, 1023, 0, 160);
    delay(1); // delay for stability
    width2 = map(analogRead(E2), 0, 1023, 160, 0); // reverse map this one
    delay(1);

    //drawBars(width1, width2, myscreen);    
    drawBarsBetter(width1, width2, myscreen);
    delay(50);  
  }
}

void drawBars(int width1, int width2, TFT &myscreen) {
    myscreen.fill(255, 10, 13); // magenta
    myscreen.rect(0, BAR1_Y, width1, 30);

    // erase any extra from the last draw by drawing a white rect over the remaining space
    myscreen.fill(255,255,255);
    myscreen.rect(width1, BAR1_Y, SCREENWIDTH - width1, 30);

    myscreen.fill(10, 228, 244); // turqoise 
    myscreen.rect(SCREENWIDTH - width2, BAR2_Y, width2, 10);
    delay(200);
}

/* 
 * A visually nicer version of the drawBars function 
 * without the flicker.
 */
void drawBarsBetter(int width1, int width2, TFT &myscreen) {
    
    // Draw the magenta line in three 10pixel high segments
    myscreen.fill(255, 10, 13); // magenta
    myscreen.rect(0, BAR1_Y, width1, 10);
    myscreen.rect(0, BAR1_Y+20, width1, 10);

    // erase any extra from the upper and lower bars of the last
    myscreen.fill(255,255,255);
    myscreen.rect(width1, BAR1_Y, SCREENWIDTH - width1, 10);
    myscreen.rect(width1, BAR1_Y+20, SCREENWIDTH - width1, 10);

    myscreen.fill(10, 228, 244); // turqoise 
    myscreen.rect(SCREENWIDTH - width2, BAR2_Y, width2, 10);

    // draw the left of the turqoise bar in red (or white)
    // Todo...
    if((SCREENWIDTH - width1 - width2) <= 0) {
      myscreen.fill(255, 10, 13);
      myscreen.rect(0, BAR1_Y+10, SCREENWIDTH - width2, 10); 
    } else {
      myscreen.fill(255,255,255);
      myscreen.rect(width1, BAR1_Y+10, SCREENWIDTH - width1 - width2, 10);
      myscreen.fill(255, 10, 13);
      myscreen.rect(0, BAR1_Y+10, width1, 10); 
    }
}



