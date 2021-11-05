/* Project R.F.I.D door lock system 
 * "THE PROGRAMING IS YOUR LOGIC"
 * 2K17 Present >>> TEKNIK ELEKTRONIKA INDUSTRI
 * SMK BKM 2
 * Design Program and Mechanic by :
 * Chandra P.W.G & Wahyu Gamma Gene
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

 
// Masukan Inisial dan library :


#include <LiquidCrystal.h>
#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
LiquidCrystal lcd(3,4,5,6,7,8);

int ledgreen = A0 ;
int ledred = A1 ;
int buz  = A2 ;
int coil = A3 ;

void setup() {

  lcd.begin (16,2) ;
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
      lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
    digitalWrite (ledred, HIGH) ;
  pinMode (coil, OUTPUT) ; 
  pinMode (ledgreen, OUTPUT) ;
  pinMode (ledred, OUTPUT) ; 
  pinMode (buz, OUTPUT) ; 
 
}

void loop() {
  
  
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.println(strID);
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  
  if (strID.indexOf("00:5F:91:7C") >= 0) {
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Hi, Chandra :) ") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    delay (80);
    digitalWrite(buz, LOW);
    digitalWrite(coil, HIGH);
    digitalWrite(ledgreen, HIGH);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    delay (200) ; 
    digitalWrite(ledred, HIGH);
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  } 
 else if (strID.indexOf("E7:14:2D:5B") >= 0) { //E6:11:0C:C5
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Hi, Ajeng :)") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    delay (80);
    digitalWrite(buz, LOW);
    digitalWrite(coil, HIGH);
    digitalWrite(ledgreen, HIGH);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    delay (200) ; 
    digitalWrite(ledred, HIGH);
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  } 
else if (strID.indexOf("8D:CF:8A:AB") >= 0) {
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Hi, Inna :)") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    delay (80);
    digitalWrite(buz, LOW);
    digitalWrite(coil, HIGH);
    digitalWrite(ledgreen, HIGH);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    delay (200) ; 
    digitalWrite(ledred, HIGH);
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  } 

else if (strID.indexOf("EE:C1:2D:5B") >= 0) {
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Adi Priansyah :)") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    digitalWrite(ledgreen, HIGH);
    digitalWrite(coil, HIGH);
    delay (300);
    digitalWrite(buz, LOW);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH);
    delay (300) ; 
    
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  } 

  else if (strID.indexOf("55:6B:2D:5B") >= 0) {
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Wahyu Jr :)") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    delay (80);
    digitalWrite(buz, LOW);
    digitalWrite(coil, HIGH);
    digitalWrite(ledgreen, HIGH);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    delay (200) ; 
    digitalWrite(ledred, HIGH);
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  } 

  else if (strID.indexOf("19:3A:4E:38") >= 0) {
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("Welcome Back") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("Arif udin ") ;
    digitalWrite(ledred, LOW);
    digitalWrite(buz, HIGH);
    delay (80);
    digitalWrite(buz, LOW);
    digitalWrite(coil, HIGH);
    digitalWrite(ledgreen, HIGH);
    delay (3000);
    digitalWrite(coil, LOW);
    digitalWrite(ledgreen, LOW);
    delay (200) ; 
    digitalWrite(ledred, HIGH);
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
return;
  }
  
 else {
    delay(30) ;
    digitalWrite(ledgreen, LOW);
    digitalWrite(coil, LOW); 
    digitalWrite(ledred, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(buz, LOW);
    delay (20) ;
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(buz, LOW);
    delay (20) ;
    
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print (" Access Denied") ;
    lcd.setCursor (0,1) ;
    lcd.print ("  Unknown User  ") ;
    delay (1000) ;
    lcd.clear ();
    lcd.begin (16,2) ;
    lcd.print ("The Door Closed") ;
    lcd.setCursor(0,1) ; 
    lcd.print ("TAP Your Card") ;
    
    
  }
}
