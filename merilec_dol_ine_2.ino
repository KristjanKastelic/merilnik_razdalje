#include <LiquidCrystal.h>


LiquidCrystal lcd(1, 2, 3, 4, 5, 6); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int LED1 = 11;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;

void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED1, OUTPUT);

}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
if (distanceCm <= 5){
  digitalWrite(LED1, LOW);
}
  else
 { 
  digitalWrite(LED1, HIGH);
 }

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;


lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print("  cm");
delay(10);

}
