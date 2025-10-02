const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

bool objectPresent = false;  
int objectCount = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
 
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
  Serial.println("Object Detected & Present");
  objectPresent = true;
  }
  } else {

  if (objectPresent) {
  Serial.println("Detected Object Is Gone");
  objectCount++;
 Serial.print(objectCount);
  Serial.println(" Objects Detected");
  objectPresent = false;
  } else {
  Serial.println("Waiting To Detect An Object");
  }
  }

  delay(300);
}
