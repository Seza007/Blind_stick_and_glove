#include <esp32cam-asyncweb.h>
#include <esp32cam.h>

#include <Servo.h>
const int servoPin = 4;        // Servo motor pin
const int trigPin = 9;         // Ultrasonic sensor trig pin
const int echoPin = 10;         // Ultrasonic sensor echo pin
const int buzzerPin = 8;        // Servo motor pin
const int trigPin2 = 7;         // Ultrasonic sensor trig pin
const int echoPin2 = 6;         // Ultrasonic sensor echo pin
const int buzzerPin2 = 5;
unsigned long previousMillis = 0; // variablle assigned for the func millis()
const long interval = 1000;  // Interval between servo movements in milliseconds
int angle = 0; // Initial angle of the servo

Servo myservo;
void setup() {
  Serial.begin(9600);

  myservo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzerPin2, OUTPUT);
}
void rotateServo() {
  unsigned long currentMillis = millis();

  // If it's time to update the servo position
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the servo was updated
    previousMillis = currentMillis;

    // Increment the angle by 30 degrees
    angle += 30;

    // Ensure angle stays within 0-180 range
    if (angle >=151) {
      angle = 40; // Reset angle
    }
  myservo.write(angle);
  Serial.print("Angle: ");
  Serial.println(angle);
  }
}
void loop() {
  rotateServo();  // Rotate the servo
  detectObstacle();
  detectObstacle2();  // Detect obstacle using ultrasonic sensor
}
void detectObstacle(){
  long duration, distance;

  // Triggering the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reading the duration of the pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculating distance
  distance = duration * 0.034 / 2;

  // Displaying the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Adjust the buzzer sound based on the distance
  if (distance < 10) {
    tone(buzzerPin, 1000, 300); // High-pitched beep with shorter duration
  }
  else if (distance < 20) {
    tone(buzzerPin, 1000, 100); // High-pitched beep with shorter duration
    delay(100); // Delay between beeps
  } else if (distance < 30) {
    tone(buzzerPin, 500, 200); // Medium-pitched beep with longer duration
    delay(100); // Delay between beeps
  } else {
    noTone(buzzerPin); // No beep
    delay(300); // Longer delay when no beep
  }
}
void detectObstacle2() {
  long duration2, distance2;

  // Triggering the ultrasonic sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Reading the duration of the pulse
  duration2 = pulseIn(echoPin2, HIGH);

  // Calculating distance
  distance2 = duration2 * 0.034 / 2;

  // Displaying the distance on the Serial Monitor
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Adjust the buzzer sound based on the distance
  if (distance2 < 10) {
    tone(buzzerPin2, 1000, 300); // High-pitched beep with shorter duration
  }
  else if (distance2 < 20) {
    tone(buzzerPin2, 1000, 100); // High-pitched beep with shorter duration
    delay(100); // Delay between beeps
  } else if (distance2 < 30) {
    tone(buzzerPin2, 500, 200); // Medium-pitched beep with longer duration
    delay(100); // Delay between beeps
  } else {
    noTone(buzzerPin2); // No beep
    delay(300); // Longer delay when no beep
  }
}
