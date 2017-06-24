 /*
 * Graphite Interface
 * 
 * This program visualizes the values coming in from the two 
 * graphite electrodes as text on the TFT screen.
 * 
 * Hardware:
 * Four electrodes dividing up a graphite drawing.
 * The outermost electrodes go to +5V and Ground
 * The inner two to A0 and A1
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
 * And in case you're wondering how itoa() works
 * https://playground.arduino.cc/Code/PrintingNumbers
 * http://www.cplusplus.com/reference/cstdlib/itoa/
 * http://www.geeksforgeeks.org/implement-itoa/
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
  myscreen.background(0,0,0); // black background
  myscreen.stroke(255,255,255); // white text
  myscreen.setTextSize(1);
  myscreen.text("E1 Value :\n", 0, 0);
  myscreen.text("E2 Value :\n", 0, 60);
  
  myscreen.setTextSize(4);

  int e1, e2;

  while(true) {
    e1 = analogRead(E1);
    delay(1); // delay for stability
    e2 = analogRead(E2);
    delay(1);

    drawText(e1, e2, myscreen);    
  }
  
  return 0;
}

void drawText(int e1val, int e2val, TFT &myscreen) {
    char e1str[10];
    char e2str[10];
    
    itoa(e1val, e1str, 10);
    myscreen.text(e1str, 0, 20);
    itoa(e2val, e2str, 10);
    myscreen.text(e2str, 0, 80);
    delay(100); // wait a moment before erasing the text

    // "erase" the text by redrawing it in black
    myscreen.stroke(0,0,0);
    myscreen.text(e1str, 0, 20);
    myscreen.text(e2str, 0, 80);
    myscreen.stroke(255,255,255);
}






