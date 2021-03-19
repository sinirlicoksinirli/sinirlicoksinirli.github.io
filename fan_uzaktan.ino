// bu kodu yusuf fidan yazmıştır çalmak yaasaktır                                               
#include <IRremote.h>
int h1l = 10;
int h2l = 11;
int h3l = 12;
int htl = 13;
int abuzer = 4;
int sgl = 8;
int fan = 9;
IRrecv irrecv(3);
decode_results results;
//buası 
#define BUTON1 0xE13DDA28
#define BUTON2 0xAD586662
#define BUTON3 0x273009C4
#define BUTON4 0xE0E010EF
#define BUTON0 0x56879C4D
void setup()
{
  Serial.begin(9600);
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
  if (irrecv.decode(&results))
  {    
    if (results.value == BUTON0) {
      singal();
      analogWrite(fan, 0);
      digitalWrite(h1l, LOW);
      digitalWrite(h2l, LOW);
      digitalWrite(h3l, LOW);
      digitalWrite(htl, LOW);

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
void singal() {
  digitalWrite(sgl, HIGH);
  digitalWrite(abuzer, HIGH);
  delay(200);
  digitalWrite(sgl, LOW);                 
  digitalWrite(abuzer, LOW);                                                                                               
}
