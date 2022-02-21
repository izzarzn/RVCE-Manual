#define BLYNK_TEMPLATE_ID "TMPLJPcNPo5q"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "Js7lgXdue3Q9pvwASZuz19U8qJD2MLjr"

#define DHTPIN 2
#define DHTTYPE    DHT11

#define BLYNK_PRINT Serial

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Free";
char pass[] = "20022005";

BlynkTimer timer;
DHT_Unified dht(DHTPIN, DHTTYPE);

// This function is called every time the Virtual Pin 0 state changes


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{

  //Write Code Here:
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print("Temperature: ");
  float temp = float(event.temperature);
  Serial.print(event.temperature);
  Blynk.virtualWrite(V1, temp);
  Serial.println("°C");

  dht.humidity().getEvent(&event);
  Serial.print("Relative Humidity: ");
  float hum = float(event.relative_humidity);
  Serial.print(hum);
  Blynk.virtualWrite(V2, hum);
  Serial.println("%");
  Serial.println("\n-------------------------------");

}
void setup()
{

  // Debug console
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
