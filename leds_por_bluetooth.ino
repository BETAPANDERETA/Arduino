#include <SoftwareSerial.h>
SoftwareSerial comunicador(7,6); //(RX,TX)
char dato = '0';
int led_1 = 2;
int led_2 = 3;
void setup() {
  comunicador.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
}
void loop() {
  if (comunicador.available()) {
    dato = comunicador.read();
    if (dato != '0') {
      if (dato == '1')digitalWrite(led_1, HIGH);
      if (dato == '2')digitalWrite(led_2, HIGH);
    }
    else {
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
    }
  }
}
