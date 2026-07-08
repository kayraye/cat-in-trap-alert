#define trigPin 12
#define echoPin 13


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  long duration, distance;
  //sending an ultrasonic pulse on the trigger pin of the sensor
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  //mearusing time between the pulse and the echo from the ultrasonic microphone
  duration= pulseIn(echoPin, HIGH);//29.1
  
 //converting the time to a distance measurment 
  distance= (duration/29.1)/2;
  Serial.println(distance);

  //turn on the led when we sense something in a certain range
  //the button should toggle weather the led will turn on 


  delay(500);
}
