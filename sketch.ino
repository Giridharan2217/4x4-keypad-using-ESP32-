#include <Keypad.h>

const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
int disp_pin[7];	/* array for a-g pins of 7-Segment display */

void define_segment_pins(int a, int b, int c, int d, int e, int f, int g)	/* Assigns 7-segment display pins to board */
{  
  disp_pin[0] = a;
  disp_pin[1] = b;
  disp_pin[2] = c;
  disp_pin[3] = d;
  disp_pin[4] = e;
  disp_pin[5] = f;
  disp_pin[6] = g;
}

void display_number(int num)	/* Function for displaying number (0-9) */
{
  switch(num)
  {
    case '0':
    digitalWrite(disp_pin[0], LOW);	/* Drive disp_pin[0] to LOW */
    digitalWrite(disp_pin[1], LOW);	/* Driving LOW turns on LED segment for common anode display */
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], HIGH); 
    break;
    case '1':
    digitalWrite(disp_pin[0], HIGH);	/* Drive disp_pin[7] to HIGH */
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], HIGH);	/* Driving HIGH turns off LED segment for common anode display */
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case '2':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], HIGH);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '3':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '4':
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '5':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '6':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], HIGH);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '7':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], HIGH);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], HIGH);
    break;
    case '8':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    case '9':
    digitalWrite(disp_pin[0], LOW);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], HIGH);
    digitalWrite(disp_pin[5], LOW);
    digitalWrite(disp_pin[6], LOW);
    break;
    default:
    digitalWrite(disp_pin[0], HIGH);
    digitalWrite(disp_pin[1], LOW);
    digitalWrite(disp_pin[2], LOW);
    digitalWrite(disp_pin[3], LOW);
    digitalWrite(disp_pin[4], LOW);
    digitalWrite(disp_pin[5], HIGH);
    digitalWrite(disp_pin[6], LOW);
    break;
  }
}

char hexaKeys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}};

  


byte rowPins[ROWS] = {13, 12, 14, 27}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {26, 25, 33, 32}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  pinMode(5, OUTPUT);	
  pinMode(17, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  define_segment_pins(5,17,0,4,16,18,19);
Serial.begin(9600);
}

void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
    display_number(customKey);
Serial.println(customKey);
  }
}