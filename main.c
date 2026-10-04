#include <TinyGPS++.h>

TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

#define RXD2 4
#define TXD2 2

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.println("GPS Debug Start...");
}

void loop() {
  while (gpsSerial.available()) {
    char c = gpsSerial.read();

    Serial.write(c);   //  RAW DATA (must appear)

    gps.encode(c);
  }

  // Show satellite count always
  Serial.print("Satellites: ");
  Serial.println(gps.satellites.value());

  // Show location if available
  if (gps.location.isValid()) {
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Lng: ");
    Serial.println(gps.location.lng(), 6);
  }

  delay(2000);
}
