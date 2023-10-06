int ul_trig = 4;
int ul_echo = 5;

int buzzer = 16;
int led = 12;

int sensor = 14;              
int state = LOW;             

int pr = A0;

void setup() {
  pinMode(ul_trig, OUTPUT);
  pinMode(ul_echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT); 
  pinMode(sensor, INPUT);
  pinMode(pr, INPUT);
  Serial.begin(9600);
}

void loop() {

  // Ultrasonic Sensor
  Serial.println();
  Serial.println("Ultrasonic Sensor");
  digitalWrite(ul_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ul_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ul_trig, LOW);

  long duration = pulseIn(ul_echo, HIGH);
  int distanceCm = duration * 0.034/2;
  int distanceInch = distanceCm * 0.393701;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  if(distanceCm < 25){
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW);
  }
  delay(1000);


  // Pir sensor
  Serial.println();
  Serial.println("PIR Sensor");
  int val = digitalRead(sensor);
  Serial.println(val);
  if (val == HIGH) {          
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);    
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(2500);          
    digitalWrite(led, LOW);
  }
  delay(1000);
  
  //photoresistor
  Serial.println();
  Serial.println("LDR");
  int photo = analogRead(pr);
  Serial.println(photo);
  if (photo > 600)
  {
    Serial.println("Light present");
  }
  else{
    Serial.println("Light absent");
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
  }

  delay(1000);
}