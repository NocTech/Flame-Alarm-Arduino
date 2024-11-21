const int buttonPin = 5;
const int ledPin = 13;
const int flamePin = 4;

int val = 0;
int buttonState = 0;
int lastButtonState = 0;
bool systemOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(flamePin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    systemOn = !systemOn;
    if (systemOn) {
      Serial.println("System ON");
    } else {
      Serial.println("System OFF");
    }
    delay(200);
  }
  lastButtonState = buttonState;

  if (systemOn) {
    val = digitalRead(flamePin);

    if (val == 0) {
      Serial.println("Warning: Fire!");
      digitalWrite(ledPin, HIGH);
    } else {
      Serial.println("No Fire");
      digitalWrite(ledPin, LOW);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
