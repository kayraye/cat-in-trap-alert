bool buttonpressed=false;
bool prevbutton=false;
bool ledvalue=false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(21,INPUT);
  pinMode(18,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if(digitalRead(21)){
  //   Serial.println("hi this is the esp32");
  //   digitalWrite(18,HIGH);
  // }
  // else{
  //   digitalWrite(18,LOW);
  // }
  buttonpressed=digitalRead(21);
  if(buttonpressed&&prevbutton==false){
    ledvalue=!ledvalue;
  }
  prevbutton=buttonpressed;

  Serial.println(ledvalue);
  if(ledvalue==true){
    digitalWrite(18,HIGH);
  }
  else{
    digitalWrite(18,LOW);
  }
}


