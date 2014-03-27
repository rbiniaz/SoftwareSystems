/*
  Use this sketch to test the SoftSysSynth.
  
  Remove the speaker and run a resistor from the emitter of the transistor to ground
  (effectively bypassing the decoupling capacitor and the speaker).
  
  Then run a wire from the emitter to A0.
  
  When you run this sketch, open the serial monitor.  The input is on the left.
  The value at A0 is on the right.  With the 0.7 V offset, the value at A0 should
  equal the input value minus ~36.
 
  Author: Allen Downey 
 
  Based on http://arduino.cc/en/Tutorial/AnalogInput
  Created by David Cuartielles, modified by Tom Igoe.

  License: Public Domain
 
 */
 
 

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 5;       // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int buttonPin1 = 2;
int buttonPin2 = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin, OUTPUT);
  
  DDRD = DDRD | B11000000; // sets pins 6 and 7 as outputs without changing 0 through 5  
  DDRB = DDRB | B00111111; // sets pins 8 through 13 as outputs without changing 14 and 15
}

void writeByte(int x) {  
  PORTD = (PORTD & B00111111) | (((x & B10000000) >> 1) | ((x & B01000000) << 1));
  PORTB = (PORTB & B11000000) | (((x & B00100000) >> 5) | ((x & B00010000) >> 3) | ((x & B00001000) >> 1) | ((x & B00000100) << 1) | ((x & B00000010) << 3) | ((x & B00000001) << 5));  
}

int counter = 0;

void loop() {
  counter += 8;
  if (counter > 255) counter = 0;
  Serial.print(counter);
  Serial.print(", ");

  // write to the digital pins  
  writeByte(counter);
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue >> 2);
  
  int button1 = digitalRead(buttonPin1);
  int button2 = digitalRead(buttonPin2);
  
  // if either button is pressed, turn on the LED
  if (button1 ^ button2) {
      digitalWrite(ledPin, HIGH);  
  } else {          
      digitalWrite(ledPin, LOW);
  }

  delay(400);  
}
