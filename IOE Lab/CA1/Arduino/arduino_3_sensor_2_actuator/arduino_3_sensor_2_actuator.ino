int ul_trig = 5;
int ul_echo = 4;

int buzzer = 2;
int led = 3;

int sensor = 6;              
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
  digitalWrite(ul_trig, HIGH);
  delay(100);
  digitalWrite(ul_trig, LOW);

  int duration = pulseIn(ul_echo, HIGH);
  Serial.print("Distance in CM: ");
  Serial.println(duration / 58);
  Serial.print("Distance in inches: ");
  Serial.println(duration / 148);

  if(duration/58<10){
    digitalWrite(buzzer, HIGH);
  }
  delay(2000);
  digitalWrite(buzzer, LOW);
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

  //photoresistor
  Serial.println();
  Serial.println("LDR");
  int photo = analogRead(pr);
  Serial.println(photo);
  if (photo > 180)
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