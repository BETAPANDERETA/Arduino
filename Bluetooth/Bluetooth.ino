/*
 * HECHO POR BETAPANDERETA; SIMULACIÓN DE ENVÍO DE DATOS A PYTHON POR BLUETOOTH
*/
#include <SoftwareSerial.h>
#include <math.h>
int rx = 10;
int tx = 11;
int info;
SoftwareSerial miBto(rx, tx);

void setup() {
  Serial.begin(9600);
  miBto.begin(9600);
  Serial.print("--------------------------");
  Serial.print("\n|PUERTO SERIAL CONECTADO|\n ");
  Serial.print("-------------------------\n ");
}

void loop() {
  if (Serial.available()) {
    info = Serial.read();
    switch ( info )
    {
      case 49 :
        makeData();
        break;
      case 48:
        miBto.print('0');
        Serial.println("TRANSMISIÓN IRRUMPIDA");
        break;
      default:
        break;
    }
  }
}

void makeData() {
  int i = 0;
  double  fx = 0;
  for (i; i <= 500; i++) {
    Serial.print("f(");
    Serial.print(i);
    Serial.print(")=");
    fx = pow(i, 2);
    Serial.print(fx);
    Serial.print("\n");
    miBto.println(fx);
  }
}
