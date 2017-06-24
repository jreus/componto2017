 /*
 * Graphite Interface
 * 
 * Circles and Rotation around an Ellipse
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
#define E2 A2

#define TWOPI 6.283185307179586 // 2 x PI
#define SW_2 80  // half screen width
#define SH_2 64  // half screen height
#define SHAPE_SIZE 3

int lastx=0, lasty=0;

int main() {
  init();

  TFT myscreen = TFT(LCD_CS, DC, RST);

  myscreen.begin();
  myscreen.background(0,0,0); // black background

  int shapesize, xpos, ypos;
  int radius_x, radius_y;
  float angle;

  myscreen.noStroke();
  while(true) {
    
    radius_y = map(analogRead(E1), 0, 1023, 2, SH_2);
    radius_x = radius_y;
    delay(2); // delay for stability
    
    angle = intMapToFloat(analogRead(E2), 0, 1023, 0.0, TWOPI); 
    delay(2);
    
    drawShapeFromCenter(myscreen, radius_x, radius_y, angle, getRed(), getBlue(), getGreen());
    delay(20);
  }
}

// This function maps one range of values linearly to another range. Inputs are integers, outputs are floats.
float intMapToFloat(int x, int inMin, int inMax, float outMin, float outMax) {
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

void drawShapeFromCenter(TFT &screen, int rad_x, int rad_y, float angle, int r, int g, int b) {
  int xpos, ypos;
  xpos = (cos(angle) * rad_x) + SW_2;
  ypos = (sin(angle) * rad_y) + SH_2;

  // draw the new circle
  screen.fill(r,g,b);
  screen.circle(xpos, ypos, SHAPE_SIZE);

  // update the last position values
  lastx = xpos;
  lasty = ypos;
}

int getRed() {
  static byte stepSize = 1;
  static byte value = 0;
  if(value >= 255) {
    stepSize *= -1;
    value = 255;
  } else if(value <= 0) {
    stepSize *= -1;
    value = 0;    
  }
  value += stepSize;
  return (int)value;  
}

int getBlue() {
  static byte stepSize = 2;
  static byte value = 30;
  if(value >= 255) {
    stepSize *= -1;
    value = 255;
  } else if(value <= 0) {
    stepSize *= -1;
    value = 0;    
  }
  value += stepSize;
  return (int)value;  
}

int getGreen() {
  static byte stepSize = -3;
  static byte value = 255;
  if(value >= 255) {
    stepSize *= -1;
    value = 255;
  } else if(value <= 0) {
    stepSize *= -1;
    value = 0;    
  }
  value += stepSize;
  return (int)value;  
}


