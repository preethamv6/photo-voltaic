#include <Servo.h>
#include <DHT11.h>

// Define sensor pins
#define LDR1 A0
#define LDR2 A1
#define DHTPIN 8
#define ERROR_MARGIN 10

const int currentPin = A4;
int sensitivity = 66;
int offsetVoltage = 2500;
int Spoint = 90;  // Initial servo angle

double adcVoltage = 0;
double currentValue = 0;
int adcValue;

// Objects
Servo servo;
DHT11 dht11(DHTPIN);

void setup() {
  servo.attach(11);      // Servo motor PWM pin
  servo.write(Spoint);   // Set starting position
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // Read temperature
  int temperature = dht11.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Read current sensor
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5200;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);

  Serial.print("Raw Sensor Value = ");
  Serial.print(adcValue);
  Serial.print("\t Voltage (V) = ");
  Serial.print(adcVoltage / 1000, 3);
  Serial.print("\t Current = ");
  Serial.println(currentValue, 3);

  // Read LDRs
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);
  int diff = abs(ldr1 - ldr2);

  // Solar tracking logic
  if (diff > ERROR_MARGIN) {
    if (ldr1 > ldr2) {
      Spoint--;
    } else if (ldr1 < ldr2) {
      Spoint++;
    }
  }

  servo.write(Spoint);
  delay(80);
}
