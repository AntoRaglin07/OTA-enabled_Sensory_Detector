/*
*   Importing required libraries
*/
#include <WiFi.h>             // For connecting ESP32 to WiFi
#include <ArduinoOTA.h>       // For enabling over-the-air updates
#include <ESP32Firebase.h>    //For Firebase
#include "DHT.h"              //For DHT11 Sensor

/*
*   Initializing Firebase
*/
#define REFERENCE_URL "----------"  // Your Firebase project reference url
Firebase firebase(REFERENCE_URL);

/*
*   Initializing DHT11 sensor
*/
#define DHT11PIN 32                 // Pin for DHT11
DHT dht(DHT11PIN, DHT11);


/*
*   Initializing H2S Sensor MQ136
*/
#define RL_H 47         //The value of resistor RL is 47K
#define m_H -0.263      //Enter calculated Slope 
#define b_H 0.42        //Enter calculated intercept
#define Ro_H 298        //Enter found Ro value
#define MQ_sensor_H 36  //Sensor is connected to A4


/*
*   Initializing NH3 Sensor MQ137
*/
#define RL 47           //The value of resistor RL is 47K
#define m -0.263        //Enter calculated Slope 
#define b 0.42          //Enter calculated intercept
#define Ro 25           //Enter found Ro value
#define MQ_sensor 34    //Sensor is connected to A4

