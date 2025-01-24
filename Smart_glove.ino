#include<SoftwareSerial.h>

SoftwareSerial B(2,3);

const int flexSensorPin1 = A0; // Connect the first flex sensor to analog pin A0
const int flexSensorPin2 = A1; // Connect the second flex sensor to analog pin A1
const int flexSensorPin3 = A2; // Connect the third flex sensor to analog pin A2

void setup() {
  Serial.begin(9600); // Initializing serial communication
  B.begin(9600);
}

void loop() {
  // Read the analog values from the flex sensors
  int flexValue1 = analogRead(flexSensorPin1);
  int flexValue2 = analogRead(flexSensorPin2);
  int flexValue3 = analogRead(flexSensorPin3);
  

  // Checking threshold to produce alphabets
  Serial.print("\n");
  Serial.println(flexValue1);
  Serial.println(flexValue2);
  Serial.println(flexValue3);

  Serial.print("\n");
  int f1=3;
  int f2=28;
  int f3=105;
  if (flexValue1<f1 and flexValue2<f2){
    // Serial.print("\n");
    Serial.print("\nthank you");
    B.print("\nthank you");

  }
  else if (flexValue1<f1 and flexValue3<f3){
    // Serial.print("\n");
    Serial.print("\nam sorry");
    B.print("\nam sorry");

  }
  else if (flexValue2<f2 and flexValue3<f3){
    // Serial.print("\n");
    Serial.print("\nhelp me");
    B.print("\nhelp me");

  }
  else if (flexValue3 <= 975 ) { // for letter c
    // Serial.print("\n");
    Serial.print("\nhow are you");
    B.print("\nhow are you");
  

  else if (flexValue2 < f2){ //for letter b
    // Serial.print("\n");
    Serial.print("\nhi");
    B.print("\nhi");
  }

  else if (flexValue1< f1)  {
    //for letter a
    Serial.print("\nam fine");
    B.print("\nam fine");
  }
  delay(1500); // Add a delay for readability, adjust as needed
}
