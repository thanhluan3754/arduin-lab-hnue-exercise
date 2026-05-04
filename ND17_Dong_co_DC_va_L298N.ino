const byte IN1 = 2;
const byte IN2 = 3;
const byte IN3 = 4;
const byte IN4 = 5;
const byte ENA = 10;
const byte ENB = 11;

const char* stateA = "";
const char* stateB = "";
int speedA = 0;

void mov(int i1, int i2, int i3, int i4, int eA, int eB) {
  digitalWrite(IN1, i1);
  digitalWrite(IN2, i2);
  digitalWrite(IN3, i3);
  digitalWrite(IN4, i4);

  analogWrite(ENA, eA);
  analogWrite(ENB, eB);

  speedA = eA;

  if (i1 == HIGH && i2 == LOW) stateA = "quay thuan";
  else if (i1 == LOW && i2 == HIGH) stateA = "quay nguoc";
  else stateA = "dung";

  if (i3 == HIGH && i4 == LOW) stateB = "quay thuan";
  else if (i3 == LOW && i4 == HIGH) stateB = "quay nguoc";
  else stateB = "dung";
}

void printStatus() {
  int percent = speedA * 100 / 255;

  Serial.println("-------------------");
  Serial.print("Toc do dong co tinh theo phan tram: ");
  Serial.print(percent);
  Serial.println(" %");

  Serial.print("Dong co A: ");
  Serial.println(stateA);

  Serial.print("Dong co B: ");
  Serial.println(stateB);
}

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  int speedMax = 255;
  int speed50 = 127;

  mov(HIGH, LOW, HIGH, LOW, speedMax, speedMax);
  printStatus();
  delay(5000);

  mov(LOW, LOW, LOW, LOW, 0, 0);
  printStatus();
  delay(5000);

  mov(LOW, HIGH, LOW, HIGH, speedMax, speedMax);
  printStatus();
  delay(5000);

  mov(LOW, HIGH, HIGH, LOW, speed50, speed50);
  printStatus();
  delay(5000);

  mov(LOW, LOW, LOW, LOW, 0, 0);
  printStatus();
  delay(5000);

  mov(HIGH, LOW, LOW, HIGH, speed50, speed50);
  printStatus();
  delay(5000);
}