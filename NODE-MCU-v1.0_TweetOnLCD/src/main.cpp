
#include <main.h>

const char* ssid     = "####";
const char* password = "####";
WiFiClient client;

uint8_t ButtonPin = D6;
uint8_t AnalogPin = A0;

int ButtonStatus =0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool sent = false;
bool idle = false;


const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;

void setup ()
{

    lcd.begin(16,2);
    lcd.init();
    lcd.backlight();
    lcd.clear();

    Serial.begin(9600);
    delay(10);

    // We start by connecting to a WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    //WiFi.disconnect(false);

    // initialize the LED pin as an output:
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ButtonPin, INPUT);
    Serial.println("..ok");

    lcd.clear();

    for (int thisReading = 0; thisReading < numReadings; thisReading++)
    {
        readings[thisReading] = 0;
    }

}

int randomidx = 0;

void loop()
{
    total = total - readings[readIndex];
    readings[readIndex] = analogRead(AnalogPin);
    total = total + readings[readIndex];
    readIndex = readIndex + 1;

    if (readIndex >= numReadings)
    {
        readIndex = 0;
    }

    average = total / numReadings;
    if(average > 15)
    {
        if(!sent)
        {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.println("     I guess    ");
            lcd.setCursor(0,1);
            lcd.println(" Its LUNCH TIME!");
            digitalWrite(LED_BUILTIN,LOW);
            SendTweet(client,lcd,randomidx%4);;
            sent = true;
            idle = false;
        }
    }
    else
    {
        if(!idle)
        {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.println("  I'm waiting,     ");
            lcd.setCursor(0,1);
            lcd.println("  Turn me on!!    ");
            idle = true;
            sent = false;
        }

        digitalWrite(LED_BUILTIN,HIGH);
        randomidx ++;
    }
    delay(1);
}
