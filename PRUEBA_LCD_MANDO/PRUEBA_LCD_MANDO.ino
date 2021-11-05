//www.elegoo.com
//2016.12.9

#include "IRremote.h"
#include <LiquidCrystal.h>

const int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 11

const int KEY_1 = 0xFF6897;
const int KEY_2 = 0xFF9867;
const int KEY_3 = 0xFFB04F;
const int KEY_4 = 0xFF30CF;
const int KEY_5 = 0xFF18E7;
const int KEY_6 = 0xFF7A85;
const int KEY_7 = 0xFF10EF;
const int KEY_8 = 0xFF38C7;
const int KEY_9 = 0xFF5AA5;

LiquidCrystal lcd(7,8,9,10,11,12);

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Preparando"); 
  delay(500);
  lcd.clear();
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.println("Listo");
    switch(results.value)
    {
      case KEY_1:
        Serial.println("POWER");
        lcd.print("Matricula");
        break;
      case KEY_2:
        lcd.print("Operadora");
        break;
      case KEY_3:
        lcd.print("Numero de serie");
        break;
      case KEY_4:
        lcd.print("Horas de vuelo");
        break;
      case KEY_5:
        lcd.print("Nombre del piloto");
        break;
      case KEY_6:
        lcd.print("Telefono");
        break;
      case KEY_7:
        lcd.print("Modelo de Dron");
        break;
       case KEY_8:
        lcd.print("Proveedor");
        break;
       case KEY_9:
        lcd.print("Locura");
        break;
    }
    delay(500);
    irrecv.resume();
    lcd.clear();
  }  
}/* --(end main loop )-- */
