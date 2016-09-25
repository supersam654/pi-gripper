// Map pins to names I can remember.
const int flexPin = 5; // Flex sensor.

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(flexPin);
  Serial.println(value);               //Print value
  delay(100);                          //Small delay
}


