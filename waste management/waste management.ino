  #define SW_VERSION "ThinkSpeak.com" //SW
    version will appears at initial LCD Display
   #include <ESP8266Wifi.h>

    const int M1_FORE = D1; //D5
    const int M1_BACK = D2; //D6
    const int Weight =D3; //D6
    const int trigPin1=D5; //D5
    const int echopin1 =D6; //D6
    const int trigPin2 =D7; //D7
    const int echopin2 =D8; //D8

    //define variables
    long duration 1,duration2;
    int distance1,distance2;

    WiFiClient client;
    WiFiServer server(80);
     
    const char* MY_SSID = "vivo 1820"
    const char* MY_PWD = "hello123";
    const char* TS_SERVER = "api.thingspeak.com";
    String TS_API_KEY ="49TH83LL0I1SJDJN";

    void connectWiFi()
    {
      Serial.print("Connecting to "+*MY_SSID);
      WiFi.begin(MY_SSID,MY_PWD);
      while (WiFi.status() !=WL_CONNECTED)
      {
        delay(1000):
        Serial.print(".")
      }
      Serial.println("");
      Serial.println("WiFi Connected");
      Serial.println("");
      Serial.begin("");
      Serial.println("Server started");
      Serial.print("Use this URL to connect:");
      Serial.print("http://");
      Serial.print(WiFi.localIP());
      Serial.println("/");
    }

  void sendDataTS(void)
{ 
      int water_value = analogRead(A0);
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = duration1*0.034/2;
      Serial.print("Distance_1: "); 
      Serial.println(distance1);
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      duration2 = pulseIn(echoPin2, HIGH);
      distance2 = duration2*0.034/2;
      Serial.print("Distance_2: "); 
      Serial.println(distance2);
 
      Serial.print("Water_Value: ");
      Serial.println(water_value);
      if(digitalRead(Weight) == LOW)
 {
      if(water_value < 700)
 {
      digitalWrite(M1_FORE,HIGH);
      delay(2000);
      digitalWrite(M1_FORE,LOW);
      delay(1000);
      digitalWrite(M1_BACK,HIGH);
      delay(2100);
      digitalWrite(M1_BACK,LOW); 
 }
  else
 {
     digitalWrite(M1_BACK,HIGH);
     delay(2000);
     digitalWrite(M1_BACK,LOW);
     delay(1000);
     digitalWrite(M1_FORE,HIGH);
     delay(2000);
     digitalWrite(M1_FORE,LOW); 
 } 
 
  if (client.connect(TS_SERVER, 80)) 
 { 
     String postStr = TS_API_KEY;
     postStr += "&field1=";
     postStr += String(distance1);
     postStr += "&field2=";
     postStr += String(distance2);
     postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: " + TS_API_KEY + "\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);
     delay(100); 
 }
  client.stop();
}
void setup() 
{
     Serial.begin(9600);
     delay(10);
     connectWifi();
     pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
     pinMode(echoPin1, INPUT); // Sets the echoPin as an Input 
     pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
     pinMode(echoPin2, INPUT); // Sets the echoPin as an Input 
     pinMode(M1_FORE, OUTPUT); // Sets the MOTOR_FORWARD as an Output
     pinMode(M1_BACK, OUTPUT); // Sets the MOTOR_BACKWARD as an Output 
     pinMode(Weight,INPUT);
     digitalWrite(Weight,HIGH);
}
void loop() 
{
     sendDataTS();
     delay(16000);
}


  



      
    
    
    


    



}

void loop() {
  // put your main code here, to run repeatedly:

}
