//*************************** NOTES IN MELODY **************************************
//In order to be able to iterate over the same integer, all notes had to be split into 8's. To make a 4, the pause between two 8's was set to 0.
static int RightHand[] = {
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,                                        //Bar1
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4,    //Bar2
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_A4,    //Bar3  
  NOTE_A4, NOTE_A4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_CS4,   //Bar4 
  NOTE_CS4, NOTE_CS4, 0, 0, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,              //Bar5   
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4,    //Bar6
  NOTE_A4, NOTE_A4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5,    //Bar7 
  NOTE_E5, NOTE_E5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4,    //Bar8 
  NOTE_E4, NOTE_E4, 0, 0, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4                 //Bar9
};

//LeftHand matches with right hand (long notes cut short, some notes removed)
static int LeftHand[] = {
  0, 0, 0, 0,  //Bar1
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,     //Bar2
  NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,     //Bar3  
  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2,     //Bar4
  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2,     //Bar5
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_CS3, NOTE_CS3, NOTE_CS3, NOTE_CS3, //Bar6
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_B2, NOTE_B2, NOTE_B2, NOTE_B2,     //Bar7
  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2,     //Bar8
  NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_A2,     //Bar9
};

//************************* NOTE TYPES ***************************************
//4 = quarter note, 8 = eighth note, etc, also called tempo:
//RightHand
/*static float NoteTypesRH[] = {
  8, 8, 8, 8,              //Bar1            8, 8, 8, 8,     (Notes without merge)
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar2            4, 4, 4, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar3            4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar4            4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar5            4, 4, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar6            4, 4, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar7            4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar8            4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar9            4, 4, 8, 8, 8, 8,
};*/
/*static float NoteTypesLH[] = {
  8, 8, 8, 8,              //Bar1 
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar2  
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar3  
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar4 
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar5        
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar6 
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar7 
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar8 
  8, 8, 8, 8, 8, 8, 8, 8,  //Bar9   
}; */


//*********************** IN BETWEEN NOTES PAUSES ********************************
int ShortP = 0;                                  //ShortPause in ms
int QP = {(SONGSPEED / 4) * NOTEGAP};  //QuaverPause in ms
int EP = {(SONGSPEED / 8) * NOTEGAP};      //EighthPause in ms
static int PauseBetweenNotesRH[] = 
{
  EP, EP, EP, EP,                                  //Bar1
  ShortP, QP, ShortP, QP, ShortP, QP, EP, ShortP,  //Bar2
  ShortP, QP, EP, EP, EP, ShortP, QP, ShortP,      //Bar3
  ShortP, QP, EP, EP, EP, ShortP, QP, ShortP,      //Bar4
  ShortP, QP, ShortP, QP, EP, EP, EP, EP,          //Bar5
  ShortP, QP, ShortP, QP, EP, ShortP, QP, ShortP,  //Bar6
  ShortP, QP, EP, EP, EP, ShortP, QP, ShortP,      //Bar7
  ShortP, QP, EP, EP, EP, ShortP, QP, ShortP,      //Bar8
  ShortP, QP, ShortP, QP, EP, EP, EP, EP,          //Bar9
};
static int PauseBetweenNotesLH[] = 
{
  EP, EP, EP, EP,                                  //Bar1
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar2
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar3
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar4
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar5
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar6
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar7
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar8
  ShortP, QP, ShortP, QP, ShortP, QP, ShortP, QP,  //Bar9
};
//********************************************************************************