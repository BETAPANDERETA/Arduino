#HECHO POR LEONARDO BETANCUR A.K.A BETAPANDERETA
import serial
import matplotlib.pyplot as plt
from drawnow import *
#VARIABLES
port = "COM6"
lista_datos=[]
#FUNCIONES
def procesar(info):
    paso = '\r' 
    dato = info.split(paso)
    for i in range (len(dato)):
        if dato[i] !='n' :
            return float(dato[i])
def hacer_graf():
    plt.ylim([0,100000])
    plt.xlim([0,200])
    plt.grid(True)
    plt.plot(lista_datos)
    plt.ion()
print("\t\t||ENCENDIDO||\n")
#MAIN
def main():
    cont = 0
    try:
        bto=serial.Serial(port, 9600)
        while True:
            data = bto.readline()
            data_dec = data.decode()
            info = procesar(data_dec)
            print("f("+str(cont)+") = ",info)
            cont+=1
            if info == 0:
                print("FIN TRANSMISIÓN")
                break
            else:
                lista_datos.append(info)
                drawnow(hacer_graf)
    except OSError:
            print("Dispositivo fuera de línea")
main()
