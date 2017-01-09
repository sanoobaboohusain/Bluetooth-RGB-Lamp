
#define GREEN 3
#define BLUE 5
#define RED 6
#define POWER 7

/*
   @author sanoob aboo husain

*/


char junk;
String inputString = "";


void setup() {

  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(POWER, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(POWER, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;
      if (inChar == '\n') {
        //Serial.println(inputString);
        parseValue(inputString);
        inputString = "";
      }
    }

    while (Serial.available() > 0)
    {
      junk = Serial.read() ;  // clear the serial buffer
    }

  }
}

void parseValue(String data) {

  int redv = 0;
  int greenv = 0;
  int bluev = 0;
  char input[12];
  data.toCharArray(input, 12);
  char * pch;
  pch = strtok (input, " ,.-");
  redv = atoi(pch);
  pch = strtok (NULL, " ,.-");
  greenv = atoi(pch);
  pch = strtok (NULL, " ,.-");
  bluev  = atoi(pch);

  lightLed(redv, greenv, bluev);
  /*Serial.print("Red: ");
    Serial.print(redv);
    Serial.print(" Green: ");
    Serial.print(greenv);
    Serial.print(" blue: ");
    Serial.println(bluev);*/


}


void lightLed(int r, int g, int b) {
  analogWrite( RED, 255 - r );
  analogWrite( GREEN, 255 - g );
  analogWrite( BLUE, 255 - b );
}


