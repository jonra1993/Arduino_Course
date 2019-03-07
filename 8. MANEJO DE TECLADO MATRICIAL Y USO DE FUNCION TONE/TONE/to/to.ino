#include "pitches.h"
int speakerPin = 11;


 
int cancion3 = 8;
int tones3[] = { NOTE_C6, NOTE_G5,NOTE_G5, NOTE_A5, NOTE_G5,0, NOTE_B5, NOTE_C6};
//    
long noteDuration3s3[] = {4, 8, 8, 4,4,4,4,4 };
long noteDuration3;
 
void setup()
{

  
}
 
void loop()
{
      for (int i = 0; i < cancion3; i++)
  {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    noteDuration3 = 1000/noteDuration3s3[i];
    tone(speakerPin, tones3[i],noteDuration3);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration3 * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
  
  delay(500);

  
}
