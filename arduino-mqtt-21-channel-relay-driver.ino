#include <Ethernet.h>// Ethernet.h library
uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x06};
#include <PubSubClient.h>
#include <Wire.h>
#include "auth.h"
String ip = "";
int inPin = 2;
int reading;
int previous = LOW;
unsigned long time = 0;
long debounce = 200;
int state = HIGH;
int mqttRetryAttempt = 0;
                      
EthernetClient ethClient;
PubSubClient mqttClient;

long previousMillis;

/*Relay pins*/
const char r1 = 22;
const char r2 = 23;
const char r3 = 24;
const char r4 = 25;
const char r5 = 26;
const char r6 = 27;
const char r7 = 28;
const char r8 = 29;
const char r9 = 30;
const char r10 = 31;
const char r11 = 32;
const char r12 = 33;
const char r13 = 34;
const char r14 = 35;
const char r15 = 36;
const char r16 = 37;
const char r17 = 38;
const char r18 = 39;
const char r19 = 40;
const char r20 = 41;
const char r21 = 42;

/* topics */
#define R1_TOPIC "r1/r1"
#define R2_TOPIC "r1/r2"
#define R3_TOPIC "r1/r3"
#define R4_TOPIC "r1/r4"
#define R5_TOPIC "r1/r5"
#define R6_TOPIC "r1/r6"
#define R7_TOPIC "r1/r7"
#define R8_TOPIC "r1/r8"
#define R9_TOPIC "r1/r9"
#define R10_TOPIC "r1/r10"
#define R11_TOPIC "r1/r11"
#define R12_TOPIC "r1/r12"
#define R13_TOPIC "r1/r13"
#define R14_TOPIC "r1/r14"
#define R15_TOPIC "r1/r15"
#define R16_TOPIC "r1/r16"
#define R17_TOPIC "r1/r17"
#define R18_TOPIC "r1/r18"
#define R19_TOPIC "r1/r19"
#define R20_TOPIC "r1/r20"
#define R21_TOPIC "r1/r21"

void receivedCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received: ");
  Serial.print(topic);
  Serial.println("");

  Serial.print("payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println("");
  if (strcmp(topic,R1_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r1, HIGH);
    } else {
      digitalWrite(r1, LOW);
    }
  } else if (strcmp(topic,R2_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r2, HIGH);
    } else {
      digitalWrite(r2, LOW);
    }
  } else if (strcmp(topic,R3_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r3, HIGH);
    } else {
      digitalWrite(r3, LOW);
    }
  } else if (strcmp(topic,R4_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r4, HIGH);
    } else {
      digitalWrite(r4, LOW);
    }
  } else if (strcmp(topic,R5_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r5, HIGH);
    } else {
      digitalWrite(r5, LOW);
    }
  } else if (strcmp(topic,R6_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r6, HIGH);
    } else {
      digitalWrite(r6, LOW);
    }
  } else if (strcmp(topic,R7_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r7, HIGH);
    } else {
      digitalWrite(r7, LOW);
    }
  } else if (strcmp(topic,R8_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r8, HIGH);
    } else {
      digitalWrite(r8, LOW);
    }
  } else if (strcmp(topic,R9_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r9, HIGH);
    } else {
      digitalWrite(r9, LOW);
    }
  } else if (strcmp(topic,R10_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r10, HIGH);
    } else {
      digitalWrite(r10, LOW);
    }
  } else if (strcmp(topic,R11_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r11, HIGH);
    } else {
      digitalWrite(r11, LOW);
    }
  } else if (strcmp(topic,R12_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r12, HIGH);
    } else {
      digitalWrite(r12, LOW);
    }
  } else if (strcmp(topic,R13_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r13, HIGH);
    } else {
      digitalWrite(r13, LOW);
    }
  } else if (strcmp(topic,R14_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r14, HIGH);
    } else {
      /* we got '0' -> on */
      digitalWrite(r14, LOW);
    }
  } else if (strcmp(topic,R15_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r15, HIGH);
    } else {
      digitalWrite(r15, LOW);
    }
  } else if (strcmp(topic,R16_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r16, HIGH);
    } else {
      digitalWrite(r16, LOW);
    }
  } else if (strcmp(topic,R17_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r17, HIGH);
    } else {
      digitalWrite(r17, LOW);
    }
  } else if (strcmp(topic,R18_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r18, HIGH);
    } else {
      digitalWrite(r18, LOW);
    }
  } else if (strcmp(topic,R19_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r19, HIGH);
    } else {
      digitalWrite(r19, LOW);
    }
  } else if (strcmp(topic,R20_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r20, HIGH);
    } else {
      digitalWrite(r20, LOW);
    }
  } else if (strcmp(topic,R21_TOPIC)==0) {
    if ((char)payload[0] == '1') {
      digitalWrite(r21, HIGH);
    } else {
      digitalWrite(r21, LOW);
    }
  }
}

void mqttconnect() {
  /* Loop until reconnected */
  while (!mqttClient.connected()) {
    Serial.print("MQTT connecting ...");
    /* client ID */
    String clientId = "Mega2560";
    /* connect now */
    if (mqttClient.connect(clientId.c_str(), serverUsername.c_str(), serverPassword.c_str())) {
      Serial.println("connected");
      /* subscribe topic */
      mqttClient.subscribe(R1_TOPIC);
      mqttClient.subscribe(R2_TOPIC);
      mqttClient.subscribe(R3_TOPIC);
      mqttClient.subscribe(R4_TOPIC);
      mqttClient.subscribe(R5_TOPIC);
      mqttClient.subscribe(R6_TOPIC);
      mqttClient.subscribe(R7_TOPIC);
      mqttClient.subscribe(R8_TOPIC);
      mqttClient.subscribe(R9_TOPIC);
      mqttClient.subscribe(R10_TOPIC);
      mqttClient.subscribe(R11_TOPIC);
      mqttClient.subscribe(R12_TOPIC);
      mqttClient.subscribe(R13_TOPIC);
      mqttClient.subscribe(R14_TOPIC);
      mqttClient.subscribe(R15_TOPIC);
      mqttClient.subscribe(R16_TOPIC);
      mqttClient.subscribe(R17_TOPIC);
      mqttClient.subscribe(R18_TOPIC);
      mqttClient.subscribe(R19_TOPIC);
      mqttClient.subscribe(R20_TOPIC);
      mqttClient.subscribe(R21_TOPIC);
    } else {
      Serial.print("failed, status code =");
      Serial.print(mqttClient.state());
      Serial.println("try again in 5 seconds");
      /* Wait 5 seconds before retrying */
      delay(5000);
      mqttRetryAttempt++;
    }
  }
}

void setup() {
 Serial.begin(9600);
  while (!Serial) {};
  Serial.println(F("MQTT Arduino Demo"));
  Serial.println();

  // setup ethernet communication using DHCP
  if (Ethernet.begin(mac) == 0) {
    //Serial.println(F("Unable to configure Ethernet using DHCP"));
    for (;;);
  }

  Serial.println(F("Ethernet configured via DHCP"));
  Serial.print("IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.println();
 //convert ip Array into String
  ip = String (Ethernet.localIP()[0]);
  ip = ip + ".";
  ip = ip + String (Ethernet.localIP()[1]);
  ip = ip + ".";
  ip = ip + String (Ethernet.localIP()[2]);
  ip = ip + ".";
  ip = ip + String (Ethernet.localIP()[3]);
  //Serial.println(ip);

  // setup mqtt client
  mqttClient.setClient(ethClient);

  /* set led as output to control led on-off */
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);
  pinMode(r9, OUTPUT);
  pinMode(r10, OUTPUT);
  pinMode(r11, OUTPUT);
  pinMode(r12, OUTPUT);
  pinMode(r13, OUTPUT);
  pinMode(r14, OUTPUT);
  pinMode(r15, OUTPUT);
  pinMode(r16, OUTPUT);
  pinMode(r17, OUTPUT);
  pinMode(r18, OUTPUT);
  pinMode(r19, OUTPUT);
  pinMode(r20, OUTPUT);
  pinMode(r21, OUTPUT);
  pinMode(inPin, INPUT);
  /* configure the MQTT server with IPaddress and port */
  mqttClient.setServer(serverHostname, 1883);
  /* this receivedCallback function will be invoked
    when client received subscribed topic */
  mqttClient.setCallback(receivedCallback);
  Serial.println("Everything Setup");
}

void loop() {
  reading = digitalRead(inPin);
    if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH){
            state = LOW;
           mqttClient.publish(R1_TOPIC, "0", false);
    }
    else {
            state = HIGH;
            mqttClient.publish(R1_TOPIC, "1", false);
    } 
      time = millis();    
  }
  previous = reading;
  
  if (!mqttClient.connected()) {
    mqttconnect();
  }
  mqttClient.loop();
}
