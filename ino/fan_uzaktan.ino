#include <IRremote.h> //ir remote kütüphanesi ekleniyor
//gerekli pinler isimlendirliyor
int RECV_PIN = 3 ;
int buz = 4 ;
int fan = 9 ;
int h1l = 10;
int h2l = 11;
int h3l = 12;
int htl = 13;
int sgl = 8;
int pil = A0;
int xisw = A1;
int xiswd;
int iscsensor = A2;
int autocool;
int autocl = A3;

IRrecv irrecv(RECV_PIN);

decode_results results;
#define kapa 0xE0E08877//tuşların hexdecimal kodları kaydediliyor
#define bir 0xE0E020DF
#define iki 0xE0E0A05F
#define uc 0xE0E0609F
#define turbo 0xE0E010EF

void setup()
{
  Serial.begin(9600);

  irrecv.enableIRIn(); // ir sesörü aktif et
  pinMode(buz, OUTPUT); //outputlar ayarlanıyor
  pinMode(fan, OUTPUT);
  pinMode(h1l, OUTPUT);
  pinMode(h2l, OUTPUT);
  pinMode(h3l, OUTPUT);
  pinMode(htl, OUTPUT);

}

void loop() {
  autocool = digitalRead(autocl); // aotocool butonundan veriler okunuyor
  //********** ısı ölçüm *****************
  int okunan_deger = analogRead(iscsensor);
  int sicaklik_gerilim = (okunan_deger / 1023.0) * 5000;
  int sicaklik = sicaklik_gerilim / 10.0;
  //********** ısı ölçüm *****************
  Serial.println(sicaklik);
  if (autocool == 1) { //autocool işlemi başaltılıyor
      if (sicaklik == -1 ) { // fanı durdur
      analogWrite(fan , 0);
      hiz0();
      nane();
    }
    if (sicaklik < 27) { //fanı 1. hızda çalıştır
      analogWrite(fan , 100);
      hiz1();
      nane();
    }
    if (sicaklik > 28) { //fanı 2. hızda çalıştır
      analogWrite(fan , 150);
      hiz2();
      nane();
    }
    if (sicaklik > 29) { //fanı 3. hızda çalıştır
      analogWrite(fan , 200);
      hiz3();
      nane();
    }
    if (sicaklik > 30) { //fanı turbo hızda çalıştır
      analogWrite(fan , 255);
      hizt();
      nane();
    }
  }
  if (irrecv.decode(&results)) {// eğer bir sinyal algılanırsa
    Serial.println(results.value, HEX);
    if (results.value == kapa) { // fanı durdur
      analogWrite(fan , 0);
      hiz0();
      nane();
    }
    if (results.value == bir) { //fanı 1. hızda çalıştır
      analogWrite(fan , 100);
      hiz1();
      nane();
    }
    if (results.value == iki) { //fanı 2. hızda çalıştır
      analogWrite(fan , 150);
      hiz2();
      nane();
    }
    if (results.value == uc) { //fanı 3. hızda çalıştır
      analogWrite(fan , 200);
      hiz3();
      nane();
    }
    if (results.value == turbo) { //fanı turbo hızda çalıştır
      analogWrite(fan , 255);
      hizt();
      nane();
    }



    irrecv.resume(); // işlem bittiten sonra diğer sinyalleri ara
  }

}
void nane () { // bip sesini fonksiyon haline getiriyoruz
  digitalWrite(buz, HIGH);
  delay(100);
  digitalWrite(buz, LOW);
}
void hiz1 (){
  digitalWrite(h1l,HIGH);
  digitalWrite(h2l,LOW);
  digitalWrite(h3l,LOW);
  digitalWrite(htl,LOW);  
}
void hiz2 (){
  digitalWrite(h1l,LOW);
  digitalWrite(h2l,HIGH);
  digitalWrite(h3l,LOW);
  digitalWrite(htl,LOW);  
}
void hiz3 (){
  digitalWrite(h1l,LOW);
  digitalWrite(h2l,LOW);
  digitalWrite(h3l,HIGH);
  digitalWrite(htl,LOW);  
}
void hizt (){
  digitalWrite(h1l,LOW);
  digitalWrite(h2l,LOW);
  digitalWrite(h3l,LOW);
  digitalWrite(htl,HIGH);  
}

void hiz0 (){
  digitalWrite(h1l,LOW);
  digitalWrite(h2l,LOW);
  digitalWrite(h3l,LOW);
  digitalWrite(htl,LOW);  
}

