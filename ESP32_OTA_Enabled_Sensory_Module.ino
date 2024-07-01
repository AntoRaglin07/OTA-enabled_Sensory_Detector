/*
*   Importing required libraries
*/
#include "credentials.h"
#include "Header.h"


void setup() {
  Serial.begin(115200);               //Begins Serial Monitor
  dht.begin();
  WiFi.begin(ssid, password);         // Connect to WiFi - defaults to WiFi Station mode

  // Ensure WiFi is connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  ArduinoOTA.begin();                 // Starts OTA
}

void loop() {

  ArduinoOTA.handle();                // Handles a code update request

/*
*   H2S Sensor MQ136
*/
  float VRL_H; //Voltage drop across the MQ sensor
  float Rs_H; //Sensor resistance at gas concentration 
  float ratio_H; //Define variable for ratio
  VRL_H = analogRead(MQ_sensor_H)*(5.0/4096.0); //Measure the voltage drop and convert to 0-5V
  Rs_H = ((5.0*RL_H)/VRL_H)-RL_H; //Use formula to get Rs value
  ratio_H = Rs_H/Ro_H;  // find ratio Rs/Ro
  float ppm_H = (pow(10, ((log10(ratio_H)-b_H)/m_H)))/10; //use formula to calculate ppm
  Serial.print("H2S in ppm: ");
  Serial.println(ppm_H);
  firebase.setFloat("sensor_2", ppm_H);


/*
*   NH3 Sensor MQ137
*/
  ArduinoOTA.handle();  // Handles a code update request
  float VRL; //Voltage drop across the MQ sensor
  float Rs; //Sensor resistance at gas concentration 
  float ratio; //Define variable for ratio
  VRL = analogRead(MQ_sensor)*(5.0/4096.0); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
  ratio = Rs/Ro;  // find ratio Rs/Ro
  float ppm = pow(10, ((log10(ratio)-b)/m))/10; //use formula to calculate ppm
  Serial.print("NH3 ppm in Air = ");
  Serial.println(ppm);  
  firebase.setFloat("sensor_1", ppm);


/*
*   Temperature and Humidity Sensor DHT11 
*/
  ArduinoOTA.handle();  // Handles a code update request
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);
  Serial.println();
  Serial.println();
  firebase.setFloat("Temperature", temp);
  firebase.setFloat("Humidity", humi);

}