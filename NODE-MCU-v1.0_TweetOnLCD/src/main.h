//
// Created by sendt on 2/16/2018.
//

#ifndef NODE_MCU_V1_0_TWEETONLCD_MAIN_H
#define NODE_MCU_V1_0_TWEETONLCD_MAIN_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Utils.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

#endif //NODE_MCU_V1_0_TWEETONLCD_MAIN_H
