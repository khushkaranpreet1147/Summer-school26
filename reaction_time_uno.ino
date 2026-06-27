int red=9;
const int ledPin = 9;
const int buttonPin = 2;

unsigned long startTime;
unsigned long reactionTime;
bool waitingForReaction = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  Serial.println("--- Reaction Timer ---");
  Serial.println("Press the button as soon as the LED turns on!");
  delay(1000);
}

void loop() {

  digitalWrite(ledPin, LOW);
  delay(random(2000, 5000));
  
  digitalWrite(ledPin, HIGH);
  startTime = millis();
  waitingForReaction = true;
 
  while (waitingForReaction) {
    if (digitalRead(buttonPin) == LOW) { 
      reactionTime = millis() - startTime;
      waitingForReaction = false;
      
      digitalWrite(ledPin, LOW);
      Serial.print("Reaction time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");
      
      delay(2000); 
      Serial.println("\nGet ready...");
    }
  }
}
