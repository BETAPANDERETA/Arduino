//HECHO POR LEONARDO BETANCUR A.K.A. BETAPANDERETA 
#include <SoftwareSerial.h>
#include <math.h>
int rx = 10;
int tx = 11;
int info;
SoftwareSerial miBto(rx, tx); //Puertos seriales asignados gracias a la librería SoftwareSerial

void setup() {
  Serial.begin(9600);
  miBto.begin(9600);
  Serial.print("--------------------------");
  Serial.print("\n|PUERTO SERIAL CONECTADO|\n ");
  Serial.print("-------------------------\n ");
}

void loop() {
  if (Serial.available()) {
    info = Serial.read(); // bytes de información que recibe del puerto serial
    if ( info == 49 and info != "") { // 49 es la cantidad (Decimal) de bytes que ocupa el caracter numérico "1"
      makeData();
    }
    else Serial.print("\nbyte sin procesar\n");
  }
}
//Función que crea unos datos para probar la recepción en python
void makeData() {
  int i = 0;
  double  fx = 0;
  for (i; i <= 500; i++) {
    Serial.print("f(");
    Serial.print(i);
    Serial.print(")=");
    fx = pow(i,2);
    Serial.print(fx);
    Serial.print("\n");
    miBto.println(fx);
  }
  miBto.print("FIN TRANSMISIÓN");
}
