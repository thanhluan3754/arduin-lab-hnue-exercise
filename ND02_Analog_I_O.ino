const byte LED = 9;
int lastVal = -1;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  int value = analogRead(A0);
  int percent = map(value, 0, 1023, 0, 100);
  int pwm = map(value, 0, 1023, 255, 0);
  int brightness = map(percent, 0, 100, 5, 1);

  if (abs(percent - lastVal) >= 2) {
    Serial.println("-------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("Do sang LED: ");
    Serial.println(brightness);

    lastVal = percent;
  }

  analogWrite(LED, pwm);
}
