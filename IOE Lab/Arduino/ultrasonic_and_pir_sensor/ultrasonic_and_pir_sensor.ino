int US_PIN_TRIG = 5;
int US_PIN_ECHO = 4;

int buzzer = 2;

int sensor = 7;              
int state = LOW;             
int val = 0;            

void setup() {
  pinMode(US_PIN_TRIG, OUTPUT);
  pinMode(US_PIN_ECHO, INPUT);
  pinMode(buzzer, OUTPUT); 
  pinMode(sensor, INPUT); 
  Serial.begin(9600);
}

void loop() {

  // Ultrasonic Sensor
  digitalWrite(US_PIN_TRIG, HIGH);
  delay(100);
  digitalWrite(US_PIN_TRIG, LOW);

  int duration = pulseIn(US_PIN_ECHO, HIGH);
  Serial.print("Distance in CM: ");
  Serial.println(duration / 58);
  Serial.print("Distance in inches: ");
  Serial.println(duration / 148);

  if(duration/58<10){
    digitalWrite(buzzer, HIGH);
  }
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(2000);


  // Pir sensor
  val = digitalRead(sensor);
  Serial.println(val);
     // read sensor value
  if (val == HIGH) {          
    digitalWrite(buzzer, HIGH);   
    delay(500);                
    digitalWrite(buzzer, LOW);

    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       
    }
  } 
  else {         
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       
    }
  }
  delay(1000);
}