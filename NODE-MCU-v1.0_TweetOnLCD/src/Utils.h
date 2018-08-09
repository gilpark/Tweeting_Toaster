//
// Created by sendt on 2/15/2018.
//

#ifndef NODE_MCU_V1_0_TWEETONLCD_UTILS_H
#define NODE_MCU_V1_0_TWEETONLCD_UTILS_H



#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

String BuildURL(String msg);
String GetRandomMessage(int opt);
String GetRandomMessage2(int opt);
void SendTweet(WiFiClient &client,LiquidCrystal_I2C &lcd,int opt);
#endif //NODE_MCU_V1_0_TWEETONLCD_UTILS_H
