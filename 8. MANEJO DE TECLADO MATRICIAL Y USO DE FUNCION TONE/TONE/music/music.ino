#include "pitches.h"
int speakerPin = 5;
int numTones = 15;
int estrofa1[] = { NOTE_G4,NOTE_A4,NOTE_G4,NOTE_E4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_E4,NOTE_D5,NOTE_D5,
                 NOTE_B5,NOTE_B5,NOTE_C5,NOTE_C5,NOTE_G4};

int estrofa2[] = { NOTE_A5,NOTE_A5,NOTE_A5,NOTE_C5,NOTE_B5,NOTE_A5,NOTE_G4,NOTE_A5,NOTE_G4,NOTE_E4,
                   NOTE_A5,NOTE_A5,NOTE_A5,NOTE_C5,NOTE_B5,NOTE_A5,NOTE_G4,NOTE_A5,NOTE_G4,NOTE_E4};
                   
int estrofa3[] = { NOTE_D5,NOTE_D5,NOTE_F5,NOTE_D5,NOTE_B5,NOTE_C5,NOTE_E5,NOTE_C5,NOTE_G4,NOTE_E4,NOTE_G4,
                   NOTE_F4,NOTE_D4,NOTE_C4};

int dragon[] = { NOTE_CS5,NOTE_CS5,NOTE_A4,NOTE_B4,NOTE_CS5,NOTE_B5,NOTE_CS5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,
                 NOTE_A4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_F4,
                 NOTE_DS4,NOTE_CS4,NOTE_F4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_G4,NOTE_F4,
                 NOTE_E4,NOTE_F4};

long noteDurations1[] = {1, 4, 2, 1 ,1, 4 , 2, 1, 1 ,2, 1,2,1,2,1};

long noteDurations2[] = {1,4,2,1,4,2,1,4,2,1,1,4,2,1,4,2,1,4,2,1};

long noteDurations3[] = {1,4,1,4,2,1,1,1,4,2,1,4,2,1};

long noteDurations4[] = {2,2,4,4,4,4,2,2,2,2,2,2,4,4,4,4,2,2,2,2,2,3,2,4,3,1,1,4,2,2,4,4,4,4,2,2,2,4,4,4,4,4};

long noteDuration;

void setup() 
{
   dragonball();
   delay(2000);
   noche();
}

void loop() 
{   

}

void dragonball()
{   
      for (int i = 0; i < 21; i++)
  {
   
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations4[i];
    tone(speakerPin, dragon[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  
  }
}

void noche()
{ 
       for (int i = 0; i < numTones; i++)
  {
   
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations1[i];
    tone(speakerPin, estrofa1[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(500);
  
    for (int i = 0; i < 20; i++)
  {
   
    int noteDuration = 1000/noteDurations2[i];
    tone(speakerPin, estrofa2[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(500);
  
    for (int i = 0; i < 14; i++)
  {
   
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations3[i];
    tone(speakerPin, estrofa3[i],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }  

}
