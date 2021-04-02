// bu kodu yusuf fidan yazmıştır çalmak yaasaktır
#include <IRremote.h>
int h1l = 10;
int h2l = 11;
int h3l = 12;
int htl = 13;
int abuzer = 4;
int sgl = 8;
int fan = 9;
int pil = A0;
int volham = 0.0;
int xisw = A1;
int xiswd;
int iscsensor = A2;
int autocd;
IRrecv irrecv(3);
decode_results results;
//buası
#define BUTON1 0xE0E020DF
#define BUTON2 0xAD586662
#define BUTON3 0x273009C4
#define BUTON4 0xE0E010EF
#define BUTON0 0xDFFB419D
#define AUTOCOOL 0xC7A5B6A3
void setup()
{
  Serial.begin(9600);
  pinMode(pil , INPUT);
  pinMode(h1l, OUTPUT);
  pinMode(h2l, OUTPUT);
  pinMode(h3l, OUTPUT);
  pinMode(htl, OUTPUT);
  pinMode(abuzer, OUTPUT);
  pinMode(sgl, OUTPUT);
  pinMode(fan, OUTPUT);
  irrecv.enableIRIn();

}

void loop()
{
  
  volham = analogRead(pil);
  xiswd = digitalRead(xisw);
  delay(500);
  int okunan_deger = analogRead(iscsensor);
  int sicaklik_gerilim = (okunan_deger / 1023.0) * 5000;
  int sicaklik = sicaklik_gerilim / 10.0;
  Serial.println(results.value, HEX);
  if (irrecv.decode(&results))
  {
    if (autocd == 1 ) {
      if (results.value == BUTON0) {
        singal();
        analogWrite(fan, 0);
        digitalWrite(h1l, LOW);
        digitalWrite(h2l, LOW);
        digitalWrite(h3l, LOW);
        digitalWrite(htl, LOW);
        autocd = 0;
        muz();

      }
      if (results.value == BUTON1) {
        singal();
        analogWrite(fan, 100);
        digitalWrite(h1l, HIGH);
        digitalWrite(h2l, LOW);
        digitalWrite(h3l, LOW);
        digitalWrite(htl, LOW);
      }
      if (results.value == BUTON2) {
        singal();
        analogWrite(fan, 150);
        digitalWrite(h1l, LOW);
        digitalWrite(h2l, HIGH);
        digitalWrite(h3l, LOW);
        digitalWrite(htl, LOW);
      }
      if (results.value == BUTON3) {
        singal();
        analogWrite(fan, 200);
        digitalWrite(h1l, LOW);
        digitalWrite(h2l, LOW);
        digitalWrite(h3l, HIGH);
        digitalWrite(htl, LOW);
      }
      if (results.value == BUTON4) {
        singal();
        analogWrite(fan, 255);
        digitalWrite(h1l, LOW);
        digitalWrite(h2l, LOW);
        digitalWrite(h3l, LOW);
        digitalWrite(htl, HIGH);
      }
      irrecv.resume();
    }
  }
  if (results.value == AUTOCOOL) {
    if (sicaklik > 30) {
      analogWrite(fan, 255);
      digitalWrite(h1l, LOW);
      digitalWrite(h2l, LOW);
      digitalWrite(h3l, LOW);
      digitalWrite(htl, HIGH);
    }

    if (sicaklik > 29) {
      analogWrite(fan, 200);
      digitalWrite(h1l, LOW);
      digitalWrite(h2l, LOW);
      digitalWrite(h3l, HIGH);
      digitalWrite(htl, LOW);
    }
  }

  if (sicaklik > 28) {
    analogWrite(fan, 150);
    digitalWrite(h1l, LOW);
    digitalWrite(h2l, LOW);
    digitalWrite(h3l, HIGH);
    digitalWrite(htl, LOW);
  }
  if (sicaklik < 27) {
    analogWrite(fan , 100);
    digitalWrite(h1l, HIGH);
    digitalWrite(h2l, LOW);
    digitalWrite(h3l, LOW);
    digitalWrite(htl, LOW);
  }

if (xiswd == 1) {
  if (volham < 800) {
    analogWrite(fan, 0);
    digitalWrite(h1l, LOW);
    digitalWrite(h2l, LOW);
    digitalWrite(h3l, LOW);
    digitalWrite(htl, LOW);
    uyari();
  }
}
}
void singal() {
  digitalWrite(sgl, HIGH);
  digitalWrite(abuzer, HIGH);
  delay(200);
  digitalWrite(sgl, LOW);
  digitalWrite(abuzer, LOW);
}
void uyari() {

  digitalWrite(abuzer, HIGH);
  delay(200);

  digitalWrite(abuzer, LOW);
}
void muz () {
  digitalWrite(abuzer , HIGH);
  delay(100);
  digitalWrite(abuzer , LOW);
  delay(100);
  digitalWrite(abuzer , HIGH);
  delay(100);
  digitalWrite(abuzer , LOW);
  delay(100);
  digitalWrite(abuzer , HIGH);
  delay(100);
  digitalWrite(abuzer , LOW);
  delay(500);
  digitalWrite(abuzer , HIGH);
  delay(300);
  digitalWrite(abuzer , LOW);
  delay(300);
  digitalWrite(abuzer , HIGH);
  delay(300);
  digitalWrite(abuzer , LOW);
  delay(100);


}
