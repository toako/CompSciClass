#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         5          
#define SS_PIN          53        

int r = 11;
int g = 10;
int b = 9;
int aud = 12;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
	Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void loop() {
  
  setRGB(255,15,0);
  delay(50);
  setRGB(0, 0, 0);
  delay(50);
  
	if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "83 F6 9B 1D")
  {
    Serial.println("ACCESS GRANTED. IDENTIFIED USER: William Kellermann");
    accessGranted();
  }
  else if (content.substring(1) == "C1 67 ED 31") {
    Serial.println("ACCESS GRANTED. IDENTIFIED USER: Tanner Helms");
    accessGranted();
  }
  else {
    Serial.println("ACCESS DENIED. CANNOT IDENTIFY USER");
    accessDenied();
  }
}

void setRGB (int redVal, int greenVal, int blueVal) {
  analogWrite(r, redVal);
  analogWrite(g, greenVal);
  analogWrite(b, blueVal);
}
void accessGranted() {
    Serial.println();
    setRGB(0,255,0);
    tone(aud, 2000, 50);
    delay(200);
    tone(aud, 5000, 50);
    delay(3000);
}
void accessDenied() {
    Serial.println();
    setRGB(255,0,0);
    tone(aud, 3000, 40);
    delay(200);
    tone(aud, 1000, 40);
    delay(3000);
}
