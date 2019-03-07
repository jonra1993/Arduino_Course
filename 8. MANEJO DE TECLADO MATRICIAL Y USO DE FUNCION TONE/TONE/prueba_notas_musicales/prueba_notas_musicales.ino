#include "pitches.h"
int speakerPin = 11;
int numTones = 8;
int tones[] = { NOTE_CS5,NOTE_DS5,NOTE_E5,NOTE_FS5,NOTE_GS5,NOTE_AS5,NOTE_B5,NOTE_CS6};



void setup()
{
   for (int i = 0; i < numTones; i++)
  {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //noteDuration = 1000/noteDurations[i];
    long noteDuration=1000/1;
    tone(speakerPin, tones[i],noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
