const int sensorPin = A0;
const int greenLed = 2;
const int yellowLed = 3;
const int redLed = 4;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float resistance = (5.0 - voltage) * 10000.0 / voltage;
  float tempK = 1.0 / (1.0/298.15 + log(resistance/10000.0)/3950.0);
  float tempC = tempK - 273.15;

  Serial.print("Temp: ");
  Serial.println(tempC);

  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);

  if (tempC < 25) {
    digitalWrite(greenLed, HIGH);
  } else if (tempC < 30) {
    digitalWrite(yellowLed, HIGH);
  } else {
    digitalWrite(redLed, HIGH);
  }
  delay(500);
}