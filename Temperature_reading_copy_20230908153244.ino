#define BLYNK_TEMPLATE_ID "TMPL31ezSPiUB"
#define BLYNK_TEMPLATE_NAME "DHT IoT sensor"
#define BLYNK_AUTH_TOKEN "gJtw5djx9cNp3RJeOXo4jov5m0eghWS9"
#include<DHT.h>
#define DHTPIN 4 // datapin in D2
#define DHTTYPE DHT11 // Name the sensor as an object
#include <BlynkSimpleEsp8266.h>

char auth[] = "gJtw5djx9cNp3RJeOXo4jov5m0eghWS9";
char ssid[] = "OnePlus Nord";
char pass[]= "15042006";
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHR Test Succesful!");
Blynk.begin(auth, ssid, pass);
Serial.println("Blynk Connected Successfully");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true); 
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("ERROR");
    return; 
  }
  Serial.println("Humidity"); //CHECK
  Serial.print(h);
  Serial.print("%");
  Serial.println("Tempertaure");  // VALUE IN C(DEFAULT)
  Serial.print(t);
  Serial.print(" degrees celsius ");
  
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);
   }
