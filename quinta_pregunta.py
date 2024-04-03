
from math import e, pow
from decimal import Decimal, getcontext
from matplotlib import pyplot
import numpy

x = 1

matriz = []

def funcion_1 ( nump ):
    
    resultado =  pow ( nump, 2 )

    resultado =  Decimal ( e ** ( - resultado ) )

    resultado = Decimal ( nump * resultado )

    return resultado

for i in range( 65 ):
    #declaramos h 
    h = Decimal ( pow( 2, i ) )
    h = Decimal ( 1 / h )

    getcontext().prec = 12

    #primera formula 

    resultado_1 = funcion_1( Decimal (x + h ) )

    resultado_1 = resultado_1 - funcion_1( x )

    resultado_1 = resultado_1 / h

    #segunda formula 

    resultado_2 =  funcion_1( Decimal (x + h ) )

    resultado_2 = resultado_2 - funcion_1( x - h )

    aux  = Decimal ( 2 * h )

    resultado_2 = resultado_2 / aux 

    #calculo del error


    aux = resultado_1.quantize(Decimal('.00001'))

    aux_2 = resultado_2.quantize(Decimal('.00001'))

    error_absoluto_1 = Decimal( resultado_1 - aux )

    error_absoluto_1 = abs( error_absoluto_1 )

    error_absoluto_2 = Decimal( resultado_2 - aux_2 )

    error_absoluto_2 = abs( error_absoluto_2 )

    #agrego los valores de una lista

    lista = [ h, resultado_1, error_absoluto_1, resultado_2, error_absoluto_2 ]
    

    #agrego los valores a una matriz 

    matriz.append( lista )
    

#inicializacion de los vectores numpy
     
vector_h = numpy.zeros( len( matriz ) )

vector_error_1 = numpy.zeros( len( matriz ) )

vector_error_2 = numpy.zeros( len( matriz ) )

nume=0  

#inserto los datos en los vectores numpy 
for lista_interna in matriz:
    vector_h[ nume ] = lista_interna[ 0 ]
    vector_error_1[ nume ] = lista_interna[ 2 ]
    vector_error_2[ nume ] = lista_interna[ 4 ]
    nume = nume+1

#muestro los puntos obtenidos a traves de una grafica 
pyplot.plot( vector_h, vector_error_1 )
pyplot.show()

pyplot.plot( vector_h, vector_error_2 )
pyplot.show()












