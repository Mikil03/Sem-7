int val = 0;
const int buzzer = 13;
const int pir = 14;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  val = digitalRead(pir);  
  Serial.println(val);   
  if (val == 1) {
    Serial.println("Motion Detected!");
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
  } else {
    Serial.println("Motion not detected!");
  }
  delay(1000);
}