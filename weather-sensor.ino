#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK D0
#define BME_MISO D1
#define BME_MOSI D2
#define BME_CS D3

#define SEALEVELPRESSURE_HPA (1013.25)

//Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  //Serial.begin(9600);
  //Serial.println(F("BME280 test"));

  //if (!bme.begin(0x76)) {
  if (!bme.begin()) {
    Particle.publish("Could not find a valid BME280 sensor, check wiring!");
    //Serial.println("Could not find a valid BME280 sensor, check wiring!");
    //while (1);
  }
  else {
      Particle.publish("BME280 Initialised");
  }
}

void loop() {
    String temp = String(bme.readTemperature());
    String pressure =  String(bme.readPressure() / 100.0F);
    String altitude = String(bme.readAltitude(SEALEVELPRESSURE_HPA));
    String humidity = String(bme.readHumidity());
    
    Particle.publish("Temperature (*c)", temp);
    Particle.publish("thingSpeakWrite_A0", "{ \"1\": \"" + temp + "\",\"2\": \"" + pressure + "\",\"3\": \"" + humidity + "\", \"k\": \"B6UJAY8N06AQR0D1\" }", 60, PRIVATE);
    delay(2000);
    Particle.publish("Pressure (hPa)", pressure);
    
    delay(2000);
    Particle.publish("Approx. Altitude (m)", altitude); 
    
    delay(2000);
    Particle.publish("Humidity (%)", humidity); 
    
    delay(2000);

    //1 minute = 60000000 microseconds

    delay(1000000);
}
