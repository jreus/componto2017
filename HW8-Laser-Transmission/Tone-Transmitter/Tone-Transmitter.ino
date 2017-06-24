/*
  Plays a melody using the Tone library.
  The melody is played on pin 9.

  This program also shows an example of how you might break up
  your programs into multiple files for a more logical and easy-to-manage
  structure. 

  All the note macros are stored in a second file, pitches.h
  this file is imported into the main program so that all your
  macros are available for use.

  Modified from Tom Igoe's tone example, created 21 Jan 2010
  modified 15 March, 2017
  by Jonathan Reus

  Original code:
  http://www.arduino.cc/en/Tutorial/Tone
 */

#include "arduino.h"
#include "pitches.h"

#define TONE_PIN 9
#define MELODY_LENGTH 8

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
};
 

int main() {
  init();

  // No pinMode statements are necessary when using the Tone library

  while(true) {
    playMelody();
    delay(250);
  }

  return 0;
}

void playMelody() {
  // Play through the notes of the melody
  for (int note = 0; note < MELODY_LENGTH; note++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8
    int duration = 1000 / noteDurations[note];
    tone(TONE_PIN, melody[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pause = duration * 1.30;
    delay(pause);
    // stop the tone playing:
    noTone(TONE_PIN);
  }
}


