#include <iostream>
#include <math.h>
#include <list>
#include <sstream>

//resultado <= 1,0823232337111381

using namespace std;

double punto(double x);
double valor();
double sumaInversa( list<double> lista );


int main()
{
	cout.precision(40);
    int numeroDecimales = 11, numeroDecimalesInverso = 16;
    double resultado = 0, resultado2 = 0,  k = 1, pi, mayor=0, nuevo;
    list<double> lista;
    stringstream ss;

    pi=valor();

    while( resultado <= 1.08232323371 )
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

	
    
    cout << "SUMATORIA DE PRECISION DOBLE "<< endl ;
    cout << "El numero mayor alcanzado en la sumatoria fue: "<< mayor << endl ;
    cout << "El resultado de la sumatoria es: "<< resultado << ", con esta cantidad de iteraciones: "<< k << endl ;
    cout << "El resultado sumando de forma inversa es: "<< resultado2 << endl ;
	
    cout << "El error absoluto de la sumatoria ascendente es: "<< 1.0823232337111381915160036965412 - resultado << endl ;
	cout << "El error absoluto de la sumatoria descendente es: "<< 1.0823232337111381915160036965412 - resultado2 << endl ;
	cout << "El error absoluto de la sumatoria ascendente es: "<< ( ( 1.0823232337111381 - resultado ) / 1.0823232337111381 ) * 100 <<"%" << endl ;
	cout << "El error absoluto de la sumatoria descendente es: "<< ( ( 1.0823232337111381 - resultado2 ) / 1.0823232337111381 ) * 100 <<"%"  << endl ;
    return 0;
}

double punto( double x )
{
    double aux;

    aux = pow( x, 4 );

    aux = 1 / aux;

    return aux;
}


double valor()
{
    double resultado;

    resultado = pow( 3.14159265358979323846, 4 );

    resultado = resultado/90; 

    return resultado;
}


