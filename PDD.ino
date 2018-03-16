#Package Delivery Detector
#Using Arduino and Raspberry Pi 

#include <SPI.h>
#include <Ethernet.h>
#define THRESHOLD 300

unsigned char fsr = 0; //The forse sensor resistor pin
int pressure = 0; //pressure on the sensor
int room = 2;
boolean delivered = true;
boolean email_sent = false;
byte mac[] = { 0xDE, 0xAD, 0xBB, 0xEF, 0xFE, 0xED };
char server[] = "192.168.3.4";
IPAddress ip(192,168,3,6);
EthernetClient client;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  pinMode(fsr, INPUT);
}

void loop() {
  pressure = analogRead(fsr); //decalring force sensing resistor pressure
  Serial.println(pressure);
  if(delivered) {
    if(pressure > THRESHOLD) {
      delivered = true;
      if(!email_sent){ 
        parcel_ishere();
      }
      email_sent = true;
    }
  } else {
    if(pressure < THRESHOLD) {
      delivered = false; //reset system.
      email_sent = false;
      Serial.println(delivered);
    }  
  }
}

void parcel_ishere() {
   //update raspberry Pi
  String data = "{\"room\":";
  data += room;
  data += "}";
  if (client.connect(server, 8081)) {
    Serial.println("connected");
    client.println("POST / HTTP/1.1");
    client.println("Host: 192.168.3.6");
    client.println("Content-Type: application/json;charset=utf-8");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.println(data);
    client.println("Connection: close");
    client.println();
  } 
  else {
    Serial.println("connection failed");
  } 
}
