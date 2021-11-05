//Definir los pins
#define BLUE 3
#define GREEN 5
#define RED 10

void setup() {
  //El pinMode lo que indica es si esta dentro o fuera pinMode (pin, mode);
  pinMode (RED, OUTPUT);
  pinMode (GREEN, OUTPUT);
  pinMode (BLUE, OUTPUT);

  //DigitalWrite indica si el led esta encendido. Si es HIGH es led on, y si es LOW es led off.
  digitalWrite(RED, HIGH);
  digitalWrite (GREEN, LOW);
  digitalWrite (BLUE, LOW);

}

//Definir las variables que vamos a tocar en el loop
int redValue;
int greenValue;
int blueValue;

void loop() {
  // put your main code here, to run repeatedly:
  #define delayTime 100

  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  for(int i = 0; i < 255; i++)
  {
    redValue--;
    greenValue++;
    //Le manda la información.
    analogWrite (RED, redValue);
    analogWrite (GREEN, greenValue);
    delay (delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i++)
  {
    greenValue--;
    blueValue++;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for(int i = 0; i < 255; i++)
  {
    blueValue--;
    redValue++;

    analogWrite(BLUE, blueValue);
    analogWrite (RED, redValue);
    delay(delayTime);
  }

}
