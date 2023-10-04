#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int sensorPin = A0;  // Analog input pin that senses Vout
int sensorValue = 0;       // sensorPin default value
int pos = 30;    // variable to store the servo position
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 4600;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value

void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop ()
{
  sensorValue = analogRead(sensorPin);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
  R = Rref * (1 / ((Vin / Vout) - 1));  // Formula to calculate tested resistor's value
  Serial.print("R: ");                  
  Serial.println(R);                    // Give calculated resistance in Serial Monitor
  delay(100);                          // Delay in milliseconds between reeds

  if (R>3000){
      for (pos = 30; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    delay(5);              // tell servo to go to position in variable 'pos'
    }
   for (pos = 0; pos <= 30; pos += 1) { // goes from 180 degrees to 0 degrees
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(10);                  // waits 15ms for the servo to reach the position
   }
  }

}            


