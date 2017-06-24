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


int main() {
  init();

  TFT myscreen = TFT(LCD_CS, DC, RST);

  myscreen.begin();
  myscreen.background(255,255,255); // use a white background
  myscreen.noStroke(); // no outlines on rectangles

  int width1, width2;

  while(true) {
    width1 = map(analogRead(E1), 0, 1023, 0, 160); // this bar gets bigger going from 0->5V
    delay(1); // delay for stability
    width2 = map(analogRead(E2), 0, 1023, 160, 0); // this bar gets smaller going from 0->5V
    delay(1);

    drawBars(width1, width2, myscreen);    
  }
}

void drawBars(int width1, int width2, TFT &myscreen) {
    // draw the first bar starting at the left side of the screen, 30pixels down (0, 30)
    myscreen.fill(255,10,13); // magenta
    myscreen.rect(0, 30, width1, 30);

    // draw the second bar starting somewhere in the middle of the screen to that it looks like
    // it's coming out of the right side of the screen, 70pixels down (SCREENWIDTH-width2, 70)
    myscreen.fill(10,228,244); 
    myscreen.rect(160-width2, 70, width2, 30);

    // erase the "empty space" for each bar by drawing a white rectangle over it
    // this gets rid of any bits left over from drawings in the past
    myscreen.fill(255,255,255);
    myscreen.rect(width1, 30, 160-width1, 30);
    myscreen.rect(0, 70, 160-width2, 30);
}



