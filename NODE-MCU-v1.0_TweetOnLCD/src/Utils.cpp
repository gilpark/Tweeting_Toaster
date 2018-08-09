//
// Created by sendt on 2/15/2018.
//

#include "Utils.h"


String BuildURL(String msg)
{
    return "post-tweet.php?msg=" + msg + "%20Time%20:%20" + String(millis());
}

String GetRandomMessage(int opt)
{
    String toReturn;
    switch (opt)
    {
        case 0:
            toReturn = "You%20really%20turn%20me%20on.%20-The%20M1%20Toaster%20Oven%20%20%20";
            break;
        case 1:
            toReturn = "Is%20it%20getting%20hot%20in%20here?%20-The%20M1%20Toaster%20Oven%20%20%20";
            break;
        case 2:
            toReturn = "Is%20that%20toast%20I%20smell?%20-The%20M1%20Toaster%20Oven%20%20%20";
            break;
        case 3:
            toReturn = "Here%20comes%20the%20food!%20-The%20M1%20Toaster%20Oven%20%20%20";
            break;
        case 4:
            toReturn = "Food%20time!%20-The%20M1%20Toaster%20Oven%20%20%20";
            break;
    }
    return toReturn;
}

String GetRandomMessage2(int opt)
{
    String toReturn;
    switch (opt)
    {
        case 0:
            toReturn = "You really turn me on.";
            break;
        case 1:
            toReturn = "Is it getting hot in here?.";
            break;
        case 2:
            toReturn = "Is that toast I smell?";
            break;
        case 3:
            toReturn = "Here comes the food";
            break;
        case 4:
            toReturn = "Food time!";
            break;
    }
    return toReturn;
}


const char* host = "cms.databashing.com";

void SendTweet(WiFiClient &client,LiquidCrystal_I2C &lcd , int opt)
{

    if (!client.connect(host, 80))
    {
        lcd.clear();
        lcd.setCursor(0,0);

        Serial.println(">>connection failed");
        lcd.println(">>Connection failed");
        return;
    }

    String url = BuildURL(GetRandomMessage(opt));

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    unsigned long timeout = millis();

    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            lcd.clear();
            lcd.setCursor(0,0);

            Serial.println(">>> Client Timeout !");
            client.stop();
            lcd.println(">>> Client Timeout !");
            return ;
        }
    }

    Serial.println();
    Serial.println("closing connection");

    delay(500);
    lcd.clear();

    lcd.setCursor(0,0);
    switch (opt)
    {
        case 0:
            lcd.println("  You really    ");
            lcd.setCursor(0,1);
            lcd.println("  turn me on.   ");
            break;
        case 1:
            lcd.println(" Is it getting  ");
            lcd.setCursor(0,1);
            lcd.println("  hot in here?  ");
            break;
        case 2:
            lcd.println("  Is that toast ");
            lcd.setCursor(0,1);
            lcd.println("    I smell?    ");
            break;
        case 3:
            lcd.println("   Here comes   ");
            lcd.setCursor(0,1);
            lcd.println("   the food!    ");
            break;
        case 4:
            lcd.println("      FOOD      ");
            lcd.setCursor(0,1);
            lcd.println("      TIME      ");
            break;
    }
    return ;
}
