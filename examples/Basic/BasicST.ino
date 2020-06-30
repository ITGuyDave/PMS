#include "PMS.h"

PMS pms(Serial);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial1.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
}

void loop()
{
  if (pms.read(data))
  {
    // Works for PMS xxxxST sensors only!
    Serial1.print("Formaldehyde (HCHO): ");
    Serial1.println(data.AMB_HCHO);

    Serial1.print("Airflow Temperature (C): ");
    Serial1.println(data.AMB_TMP);

    Serial1.print("Airflow Humidity (%H): ");
    Serial1.println(data.AMB_HUM);

    Serial1.println();
  }

  // Do other stuff...
}