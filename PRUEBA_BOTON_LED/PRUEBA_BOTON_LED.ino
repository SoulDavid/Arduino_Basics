int ledPin = 5;
int ledPin2 = 3;
int buttonAPin = 9;
int buttonBPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);
  pinMode (ledPin2, OUTPUT);

  //Input_PULLUP sirve sobre todo para botones, para detectar la pulsación
  pinMode (buttonAPin, INPUT_PULLUP);
  pinMode (buttonBPin, INPUT_PULLUP);

  
  digitalWrite(ledPin2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonAPin) == LOW)
  {    
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  else if(digitalRead(buttonBPin) == LOW)
  {    
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin, LOW);
  }
}
