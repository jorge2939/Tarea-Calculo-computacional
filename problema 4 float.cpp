#include <list>
#include <iostream>
float ascenDescend(float x[], float y[],int i );//sirve para el ascendente o descendente depende del valor entero de i

void n3(float x[], float y[] );/*esto crea dos listas uno para negativos y otra para positivos al ordenar la lista
 quedan en el siguiente orden pos:5,4,3,2,1 neg:-1,-2,-3,-4,-5 por tanto si quito del primero obtendre el mayor de los positivos
 y el menor de los negativos, para el otro caso solo hago lo mismo pero desde el final al inicio.*/
using namespace std;
float menor(list<float> l);//complemento de n3 para pos mayor a menor
float mayor(list<float> l);//complemento de n3 para pos menor a mayor
int main()
{
	
	float x[5] = {2.718281828, 
                -3.141592654, 
                1.414213562, 
                0.5772156649, 
                0.3010299957};
    float y[5] =  {1486.2497, 
                     878366.9879, 
                     -22.37492, 
                     4773714.647, 
                     0.000185049};
    float result;
    cout.precision(10);//copiado de datos y declaraciones varias
    
	result = ascenDescend(x,y,0);//impresion de resultados inicio
    cout <<"ascendente: " << result<< endl;
    
	result = ascenDescend(x,y,5);
    cout << "descendente: " << result<< endl;
    
    n3(x,y);//impresion de resoltadosfin
    
	return 0;
}
float ascenDescend(float x[], float y[],int i )
{
	float result;
	result=0;
	if(i>1)//para calcular descendente
	{
		for(i=4; i>=0; i--)
		{
			result+=x[i]*y[i];
			
		}
	}
	else //para calcular ascendente
	{
		for(i=0; i<=4; i++)
		{
			result+=x[i]*y[i];
		}
	}
	return result;
}
void n3(float x[], float y[] )
{
	float a[5],sumap,suman;
	
	list<float> pos, neg;
	for(int i=0; i<=4; i++)//punto producto
	{
		a[i]=x[i]*y[i];
	}
	for(int i=0; i<=4; i++)//separo listas de positivos y negativos
	{
		if(a[i]>0)
		{
			pos.push_back(a[i]);
		}
		else
		{
			neg.push_back(a[i]);
		}
	}
	pos.sort();
	neg.sort();
	cout <<"Orden del mayor al menor: " << mayor(pos) +mayor(neg)<< endl;
	cout <<"Orden del menor al mayor " << menor(pos) + menor(neg)<< endl;
}
float mayor(list<float> l)
{
	float suma=0;
	
	while(!l.empty())
	{
		
		suma+=l.back();
		l.pop_back();
	}
	return suma;
}
float menor(list<float> l)
{
	float suma=0;
	
	while(!l.empty())
	{
		suma+=l.front();
		l.pop_front();
	}
	return suma;
}
