
#include "pitches.h"

int parlante=11;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
void setup()
{
  //tone(speaker,1000);

}

void loop()
{
   tone(parlante,1000);
  delay(500);
  noTone(parlante);
  delay(500);
}
