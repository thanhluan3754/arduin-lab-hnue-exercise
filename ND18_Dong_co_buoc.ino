#include <Stepper.h>
#define STEPS 2048
int lastVal = -1;
int dem = -1;

Stepper stepper(STEPS, 8, 10, 9, 11);

void quayGoc(float goc) {
  int step = goc * STEPS / 360;
  stepper.step(step);
}

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(11);
}

void loop() {
  int value = analogRead(A0);
  int percent = map(value, 0, 1023, 0, 100);
  int angle = map(percent, 0, 100, 0, 90);

  if (abs(percent - lastVal) >= 2) {
    Serial.println("--------------------------");

    Serial.print("Gia tri bien tro phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("Goc quay: ");
    Serial.print(angle);
    Serial.println("do");

    dem++;
    Serial.print("Luot quay: ");
    Serial.println(dem);

    lastVal = percent;
  }

  quayGoc(angle);
  delay(2000);
}