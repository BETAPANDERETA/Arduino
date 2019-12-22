##HECHO POR LEONARDO BETANCUR A.K.A. BETAPANDERETA
import serial
port="COM6"
cont = 0
lista_datos=[]
print("||ENCENDIDO||")
try:
    bto=serial.Serial(port, 9600)
    while True:
        data = bto.readline()
        print("f("+str(cont)+") = ",data.decode())
        lista_datos.append(data)
        cont+=1
    print(lista_datos)
except OSError:
        print("Dispositivo fuera de línea")
