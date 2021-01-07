#include <SPI.h>
#include <WiFiNINA.h>

#define led 25

char ssid[] = "xxxxxxxx";
char pass[] = "12345678";
int keyIndex = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

String readString;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    Serial.print("\n");
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  server.begin();

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100)
        {
          readString += c;
          Serial.write(c);
          
          if (c == '\n') {
            client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?blinklight\"\">Blink light</a><br />");
            client.println("<a href =\"/?stop\"\"</a><br />");     

            delay(1);
            
            bool endLoop = false;
            
            if(readString.indexOf("?lighton") > 0)
            {
              endLoop = true;
              digitalWrite(led, HIGH);
              delay(1);
            }
            else if(readString.indexOf("?lightoff") > 0)
            {
              endLoop = true;
              digitalWrite(led, LOW);    
              delay(1);
            }
            else if(readString.indexOf("?blinklight")> 0)
            {
              do
              {
                digitalWrite(25,HIGH);
                delay(1);
              }
              while(endLoop == false);
              digitalWrite(25,LOW);
              delay(1);
            }
            readString = "";         
            delay(1);
            client.stop();
            Serial.println("client disonnected");
          }
        }
      }
    }
  }
}
