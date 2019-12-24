#HECHO POR LEONARDO BETANCUR A.K.A BETAPANDERETA
import serial
import time
#VARIABLES
sec = 10
port = "COM6"
lista_datos=[]
#FUNCIONES
def procesar(info):
    paso = '\r' 
    dato = info.split(paso)
    for i in range (len(dato)):
        if dato[i] !='n' :
            return dato[i]
def convert_data(lista):
    for i in range (len(lista)):
        if lista[i] == "\x000.00":
            lista[i] == "000.00"
    return lista
    
print("\t\t||ENCENDIDO||\n")
##MAIN}
def main():
    cont = 0
    try:
        bto=serial.Serial(port, 9600)
        while True:
            while bto.inWaiting()== False:
                print("CONECTANDO ...")
                time.sleep(sec)
                if bto.inWaiting()== True:
                    print("¡CONECTADO!")
                    continue
            data = bto.readline()
            data_dec = data.decode()
            if data == '0':
                print("FIN TRANSMISIÓN")
                break
            else: 
                print("f("+str(cont)+") = ",data_dec)
                lista_datos.append(procesar(data_dec))
                cont+=1
        if len(lista_datos)!= 0:
            print(convert_data(lista_datos))
    except OSError:
            print("Dispositivo fuera de línea")
            print(lista_datos)
main()
