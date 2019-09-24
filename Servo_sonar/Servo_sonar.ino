#include <Servo.h>
Servo myservo; // creating a servo object used in controlling the servo
int degree = 0;  // variable used to store the location of the servo

const int trigPin = 10;
const int echoPin = 11;
int distance;
long duration;

void setup() {
  myservo.attach(12); // servo object connected to the servo on pin 8
  pinMode (trigPin, OUTPUT);  //trigPin set as Output
  pinMode (echoPin, INPUT);  //echoPin set as Input
  Serial.begin(9600); //Baud rate set serial communication

}

void loop() {
  for (int degree = 0; degree <=180; degree +=1){  //servo rotates from 0 to 180 degrees in steps of 1 degree
    myservo.write(degree);  // servo go to location at variable degree
    delay(20); // servo motor rotates one degree in 10 milliseconds
    distance = calcDistance();  //calls the function for calculating distance
    Serial.print (degree);
    Serial.print(",");
    Serial.print (distance);
    Serial.print (".");
    
  }
  for (int degree = 180; degree >= 0; degree -=1){  //servo rotates from 180 to 0 degree in steps of 1 degree
    myservo.write(degree);  // servo does to the location in variable degree
    delay(20); // servo motor rotates one degree in 10 milliseconds
    distance = calcDistance();  //calls the function for calculating distance
    Serial.print (degree);
    Serial.print(",");
    Serial.print (distance);
    Serial.print (".");
  }
}
int calcDistance() {  //function for calculating distance
  digitalWrite (trigPin, LOW); //Ensures that the sonar starts at a low state
  delayMicroseconds(2);
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigPin, LOW);

  duration = pulseIn (echoPin, HIGH); //measures the time taken for the echoPin to detect the signal sent by the trigPin
  distance = (duration/2) * 0.0343; // Time is divided by two to obtain the return period only
  // Speed of sound is 343m/s == 0.0343cm/microsecond
  // Distance is obtained by multiplying the speed and the time taken
  return distance;
    }
