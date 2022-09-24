void setup() 
{
  // put your setup code here, to run once:
  const int Pin=0;  
  const int limit=480;
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop()
 {
  int value;
  value=analogRead(Pin);
  Serial.println("analog value:");
  Serial.println(value);
  delay(1000);
  if (limit < 480); 
  {
    digitalWrite(13,HIGH);
  }
  else:
  {
    digitalWrite(13,LOW);
  }
  // put your main code here, to run repeatedly:

}



  // put your main code here, to run repeatedl
