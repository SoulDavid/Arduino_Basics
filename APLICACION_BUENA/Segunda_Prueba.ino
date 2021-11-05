//www.elegoo.com
//2016.12.9

#include "IRremote.h"
#include <LiquidCrystal.h>

int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 11
LiquidCrystal lcd (7,8,9,10,11,12);
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*documentos*/
String publicidad = "European Flyers";
int NumeroPublicidad = publicidad.length();

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  lcd.begin(16,2);
  lcd.print("Preparando");
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */


/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
      case 0xFF6897: lcd.clear(); lcd.setCursor (0,0); lcd.print(publicidad);//Mueve el texto a la izquierda tantas veces como su longitud
      lcd.setCursor (16,1); lcd.print(publicidad);

      for (int posicion = 0; posicion < NumeroPublicidad; posicion++)
      {
        lcd.scrollDisplayLeft();
        delay(300);
      }
    
      //Mueve el texto a la derecha tantas veces como su longitud, mas 16, que es el tamaño de la pantalla
      for (int posicion = 0; posicion < (16 + NumeroPublicidad); posicion++)
      {
        lcd.scrollDisplayRight();
        delay(300);
      }
    
      //Mueve el texto a la izquierda hasta quedar el su posicion inicial
      for (int posicion = 0; posicion < 16; posicion++)
      {
        lcd.scrollDisplayLeft();
        delay(300);
      } break;
      
      case 0xFF30CF: lcd.clear(); lcd.setCursor(0,0); lcd.print("LOCALIDAD"); lcd.setCursor(0,1); lcd.print("MADRID"); Serial.println("1");    break;
      case 0xFF18E7: lcd.clear(); lcd.setCursor(0,0); lcd.print("NUMERO DE SERIE"); lcd.setCursor(0,1); lcd.print("07DJD9J0C10100"); Serial.println("2");    break;
      case 0xFF7A85: lcd.clear(); lcd.setCursor(0,0); lcd.print("OPERADORA"); lcd.setCursor(0,1); lcd.print("SERVIVANT"); Serial.println("3");    break;
      case 0xFF10EF: lcd.clear(); lcd.setCursor(0,0); lcd.print("TFNO DE CONTACTO"); lcd.setCursor(0,1); lcd.print("666 11 22 33"); Serial.println("4");    break;
      case 0xFF38C7: lcd.clear(); lcd.setCursor(0,0); lcd.print("MODELO DRON"); lcd.setCursor(0,1); lcd.print("DJI PHANTOM4 PRO"); Serial.println("5");    break;
      case 0xFF5AA5: lcd.clear(); lcd.setCursor(0,0); lcd.print("CATEGORIA"); lcd.setCursor(0,1); lcd.print("MULTIRROTOR"); Serial.println("6");    break;
      case 0xFF42BD: lcd.clear(); lcd.setCursor(0,0); lcd.print("PILOTO"); Serial.println("7"); lcd.setCursor(0,1); lcd.print("DAVID MARTIN");   break;
      case 0xFF4AB5: lcd.clear(); lcd.setCursor(0,0); lcd.print("TFNO CONTACTO"); lcd.setCursor(0,1); lcd.print("660 387 029"); Serial.println("8");    break;
      case 0xFF52AD: lcd.clear(); lcd.setCursor(0,0); lcd.print("PESO DRON"); lcd.setCursor(0,1); lcd.print("DE 0 A 5 KG"); Serial.println("9");    break;
      case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
      
      default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
