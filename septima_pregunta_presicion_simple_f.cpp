#include <iostream>
#include <math.h>
#include <list>
#include <sstream>

//resultado <= 1,0823232337111381

using namespace std;

float punto(float x);
float valor();
float sumaInversa( list<float> lista );


int main()
{
	cout.precision(40);
    int numeroDecimales = 11, numeroDecimalesInverso = 16;
    float resultado = 0, resultado2 = 0,  k = 1, pi, mayor=0, nuevo;
    list<float> lista;
    stringstream ss;

    pi=valor();

    while( resultado <= 1.08232 )
    {
        nuevo = punto( k );
        
        lista.push_front( nuevo );

        resultado += nuevo;
		
        if ( nuevo > mayor )
        {
            mayor = nuevo;
        }

        k++;
    }

    while ( !lista.empty() )
    {
        resultado2 = resultado2 + lista.front();
        lista.pop_front();
    }

	
    
  
    cout << "SUMATORIA DE PRECISION SIMPLE "<< endl ;
    cout << "El numero mayor alcanzado en la sumatoria fue: "<< mayor << endl ;
    cout << "El resultado de la sumatoria es: "<< resultado << ", con esta cantidad de iteraciones: "<< k << endl ;
    cout << "El resultado sumando de forma inversa es: "<< resultado2 << endl ;
	
    cout << "El error de la sumatoria ascendente es: "<< 1.0823232337111381915160036965412 - resultado << endl ;
	cout << "El error de la sumatoria descendente es: "<< 1.0823232337111381915160036965412 - resultado2 << endl ;
	cout << "El error absoluto de la sumatoria ascendente es: "<< ( ( 1.0823232337111381 - resultado ) / 1.0823232337111381 ) * 100 <<"%" << endl ;
	cout << "El error absoluto de la sumatoria descendente es: "<< ( ( 1.0823232337111381 - resultado2 ) / 1.0823232337111381 ) * 100 <<"%"  << endl ;

    return 0;
}

float punto( float x )
{
    float aux;

    aux = pow( x, 4 );

    aux = 1 / aux;

    return aux;
}


float valor()
{
    float resultado;

    resultado = pow( 3.14159265358979323846, 4 );

    resultado = resultado/90; 

    return resultado;
}


