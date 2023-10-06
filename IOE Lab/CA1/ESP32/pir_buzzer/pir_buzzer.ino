void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int val = analogRead(A0);  
  Serial.println(val);   
  if (val<=280) {
    Serial.println("Dark!");
  } else {
    Serial.println("Light");
  }
  delay(2000);
}