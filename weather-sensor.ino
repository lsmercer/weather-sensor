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
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  //if (!bme.begin(0x76)) {
  if (!bme.begin()) {

    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    //while (1);
  }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println("test");
    delay(20000);
}
