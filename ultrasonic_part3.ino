const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

bool objectPresent = false;  

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;  


  const int limit = 15;  

  if (distance > 0 && distance < limit) {
  
 if (!objectPresent) {
  
  Serial.println("Object seen & Present");
  objectPresent = true;
  }
  } else {
  
  if (objectPresent) {
  
  Serial.println("object is gone");
  objectPresent = false;
  } else {
  
  Serial.println("waiting for object");
  }
  }

  delay(300);  
}
