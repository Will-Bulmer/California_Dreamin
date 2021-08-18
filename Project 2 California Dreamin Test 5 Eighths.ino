// Template obtained from https://arduinogetstarted.com/reference/tone
//Piano music sheet sourced at https://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0153433
//Arduino Protothread Template at https://roboticsbackend.com/arduino-protothreads-tutorial/
//Decay Envelope of a piano waveform at https://dsp.stackexchange.com/questions/54176/what-is-the-approximate-function-for-amplitude-of-a-plucked-string-over-time
//PWM signal not compatible with a sqaure wave from tone.

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/reference/tone
 */

const int SONGSPEED = 1112;
const float NOTEGAP = 1.1;  //+20% of the note's length
#include "pitches.h"
#include "notes.h"

//VARIABLES
const int BUZZERPINRH = 9;  //RH - RightHand
const int BUZZERPINLH = 10;  //LH - LeftHand
// Narrow the pulse width to control volume.
// Maintain same frequency by changing the off-time.
float PulseWidthRH = 0.9;  //Ratio of on to off
float PulseWidthLH = 0.9;
const int SIZERH = sizeof(RightHand) / sizeof(int);  //No. Notes per melody
const int SIZELH = sizeof(LeftHand) / sizeof(int);
static float NoteTypesRH = 8;
static float NoteTypesLH = 8;  
int NoteDurations = SONGSPEED / NoteTypesRH;  //In ms
unsigned long HalfPeriodRH [SIZERH];
unsigned long HalfPeriodLH [SIZELH];
#define PI 3.14159265358979323846264338327950

bool 


//**************************** HANDMADE FREQUENCIES *************************************

void setup()
{
  pinMode(BUZZERPINRH, OUTPUT);
  pinMode(BUZZERPINLH, OUTPUT);
  init();

  //********************** FREQUENCIES ***********************

  for (static int n = 0; n < SIZERH; n++)
  {
    //Notes Frequencies
    if (RightHand[n] != 0)
    {
      HalfPeriodRH[n] = 1000000L / RightHand[n] / 2 ;  //In micro s
    }
    else
    {
      HalfPeriodLH[n] = 0;
    }
        if (LeftHand[n] != 0)
    {
      HalfPeriodLH[n] = 1000000L / LeftHand[n] / 2 ;  //In micro s
    }
    else
    {
      HalfPeriodLH[n] = 0;
    }
  }
  //*******************************************************************************
  static unsigned long StartTime = 0;  //'Unsigned' can never be negative.
  int ThisNote = 0;
  static unsigned long PauseBegin = 0;
  while (ThisNote < SIZERH)
  {
    StartTime = millis();  //Time counter.
    while (millis() - StartTime < NoteDurations)
    {
      float OnTimeRH = HalfPeriodRH[ThisNote] * PulseWidthRH;
      float OffTimeRH = HalfPeriodRH[ThisNote] * (1-PulseWidthRH);

      
      digitalWrite(BUZZERPINRH, HIGH);
      delayMicroseconds(OnTimeRH);
      digitalWrite(BUZZERPINRH, LOW);
      delayMicroseconds(OffTimeRH);

      /*float OnTimeLH = HalfPeriodLH[ThisNote] * PulseWidthLH;
      float OffTimeLH = HalfPeriodLH[ThisNote] * (1-PulseWidthLH);
      digitalWrite(BUZZERPINLH, HIGH);
      delayMicroseconds(OnTimeLH);
      digitalWrite(BUZZERPINLH, LOW);
      delayMicroseconds(OffTimeLH);*/
    }
    //Try to play two notes in rapid succession to sound like one long note.
    if (PauseBetweenNotesRH[ThisNote] == ShortP)
    {
    }
    else if (PauseBetweenNotesRH[ThisNote] != ShortP)
    {
      delay(PauseBetweenNotesRH[ThisNote]);
    }
   /*if (PauseBetweenNotesLH[ThisNote] == ShortP)
    {
    }
    else if (PauseBetweenNotesLH[ThisNote] != ShortP)
    {
      delay(PauseBetweenNotesLH[ThisNote]);
    }*/
    ThisNote++;
  }
}
 

//*************************** EXTRA STUFF **********************************
/*
        //Waveform Envelope.

        int TimeS = millis() * 100;  //Time elapsed in seconds/10.
        float AngVel = 2 * PI * RightHand[ThisNote];  //Angular velocity.

        float Wave1 = 0.6 * sin(1*AngVel*TimeS) * exp(-0.0015*AngVel*TimeS);
        float Wave2 = 0.4 * sin(2*AngVel*TimeS) * exp(-0.0015*AngVel*TimeS);
        float Wave3 = Wave1 + Wave2;
        double Wave4 = pow(Wave3, 3);
        float RHWaveform1 = Wave4 * (1 + 16*(TimeS*exp(-6*TimeS)));
*/
//********************************************************************************
void loop() { 
}