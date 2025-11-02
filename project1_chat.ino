int led1 = 4;
int led2 = 6;
int led3 = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); 

    command.trim(); 

    if (command.equalsIgnoreCase("ON1")) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if (command.equalsIgnoreCase("ON2")) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
    }
    else if (command.equalsIgnoreCase("ON3")) {
      digitalWrite(led3, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
    else if (command.equalsIgnoreCase("ONALL")) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
    else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
  }
}