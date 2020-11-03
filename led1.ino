int ledPin = 13;
int cmd = -1;
int flag = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    cmd = Serial.read();
    flag = 1;
  }

  if (flag == 1) {
    if (cmd == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED: off");
    } else if (cmd == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED: on");
    } else {
      Serial.print("unknown command: ");
      Serial.write(cmd);
      Serial.print(" (");
      Serial.print(cmd, DEC);
      Serial.print(")");

      Serial.println();
    }

    flag = 0;    
    cmd = 65;
  }

  Serial.flush();
  delay(100);
}
