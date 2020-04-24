// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>


#define DHTTYPE DHT11	
#define DHTPIN D7   
#define min_temp  24

DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(9600); 
    dht.begin();
}

void loop() {
    delay(2000);
    
    
  float t = dht.getTempCelcius();
  if (t <= min_temp) {
      String temp1 = String(t);
      Particle.publish("temp-low", temp1);
      }
  else {
      String temp1 = String(t);
      Particle.publish("temp-normal", temp1);
  }

  delay(28000);               // Wait for 30 seconds

}

