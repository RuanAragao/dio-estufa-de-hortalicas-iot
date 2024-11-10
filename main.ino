// Desafio DIO - Estufa de hortaliças IoT
// Curso: IoT Specialist
// Aluno: Ruan Carlos Aragão Sousa
// Email: ruanaragao2@gmail.com
//

const int sensorPin = 0;
const int buzzerPin = 7;
const int fanPin = 6;
const int ledFanPin = 12;
const int ledBuzzerPin = 13;

int val = 0;
float celsius=0.0;
bool fanEnabled = false;
bool buzzerEnabled = false;


void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(ledFanPin, OUTPUT);
  pinMode(ledBuzzerPin, OUTPUT);
}

void loop()
{
  // getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);  

  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = reading * 5.0;
  voltage /= 1024.0; 

  // print out the voltage
  // Serial.print(voltage); Serial.println(" volts");

  // Temperature in C
  float temperature = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
  //to degrees ((voltage - 500mV) times 100)
  //Serial.print(temperature); Serial.println(" degrees C");
  
  if (temperature >= 50) {
    if (!buzzerEnabled){
    	buzzerEnabled = true;
      	digitalWrite(buzzerPin, HIGH);
      	digitalWrite(ledBuzzerPin, LOW);
    	Serial.println("Turn on buzzer");
    }
  } else {
  	if (buzzerEnabled){
    	buzzerEnabled = false;
      	digitalWrite(buzzerPin, LOW);
      	digitalWrite(ledBuzzerPin, HIGH);
    	Serial.println("Turn off buzzer");
    }
  }
  
  if (temperature >= 30) {
    if (!fanEnabled) {
    	fanEnabled = true;
      	digitalWrite(fanPin, HIGH);
      	digitalWrite(ledFanPin, LOW);
  		Serial.println("Turn on fan");
    }
  } else {
  	if (fanEnabled) {
    	fanEnabled = false;
      	digitalWrite(fanPin, LOW);
      	digitalWrite(ledFanPin, HIGH);
  		Serial.println("Turn off fan");
    }
  }
  
  
  delay(1000);
}
