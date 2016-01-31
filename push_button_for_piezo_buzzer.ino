/* Play Melody
 * -----------
 * 
 * Program to play a simple melody
 * 
 * Tones are created by quickly pulsig a speaker on and off
 * using PWM, to create signature frequencies.
 * 
 * Each note has a frequency, created by varying the period of
 * vibration, measured in microseconds. We'll use pulse-width
 * modulation (PWM) to create that vibration.
 * 
 * We calculate the pulse-width to be half the period; we pulse
 * the speaker HIGH for 'pulse-width' microseconds, then LOW
 * for 'pulse-width' microseconds. This pulsing creates a vibration 
 * of the desired frequency.
 */

#include "pitches.h"
#include "led.h"
#include "piezo_buzzer.h"
#include "button.h"    

// note , beat
int notes[] = {
  NOTE_C8,
  NOTE_B7,
  NOTE_G7,
  NOTE_C8,
  NOTE_B7,
  NOTE_E7,
  NOTE_R,
  NOTE_C8,
  NOTE_C7,
  NOTE_G7,
  NOTE_A7,
  NOTE_C8
};

int beats[] = {
  16,
  16,
  16,
  8,
  8,
  16,
  32,
  16,
  16,
  16,
  8,
  8
};

PushButton myButton(7);
LEDPin myLED(13);
int songLength = sizeof(notes) / 2;
PiezoBuzzer myBuzzer(9, notes, beats, songLength, 100, 10000, 1000);

void setup() {
    Serial.begin(9600);
}

void loop() {
  if (myButton.checkStatus() == HIGH) {
    myLED.setOff();
  } else {
    myLED.setOn();
    Serial.print("Max count: ");
    Serial.println(myBuzzer._songLength);
    myBuzzer.playSong();
  }
}
