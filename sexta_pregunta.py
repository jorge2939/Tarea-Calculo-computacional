from math import pow
from decimal import Decimal
from matplotlib import pyplot
import numpy as np

eje_x = np.zeros(101)
resultado_1 = np.zeros(101)
resultado_2 = np.zeros(101)
resultado_3 = np.zeros(101)


x = Decimal(0.99000000)
valor_constante = Decimal(0.00019802)

numbers = list()

def func_1(x):
  return Decimal(Decimal(pow(x,8)) - 8*(Decimal(pow(x,7))) + 28*Decimal(pow(x,6)) -56*(Decimal(pow(x,6)))+ 70*Decimal(pow(x,4))\
      - 56*Decimal(pow(x,3)) + 28*Decimal(pow(x,2)) - 8*x + 1)

def func_2(x):
  return Decimal((((((((x-8)*x + 28)*x - 56)*x + 70)*x - 56)*x + 28)*x - 8)*x + 1)

def func_3(x):
  return Decimal(Decimal(pow(x-1,8)))


i = 0
while(x <= 1.01000000):
  eje_x[i] = x
  resultado_1[i] = func_1(x)
  resultado_2[i] = func_2(x)
  resultado_3[i] = func_3(x)

  i += 1
  x = x + valor_constante


pyplot.plot( eje_x, resultado_1 )
pyplot.plot( eje_x, resultado_2)
pyplot.plot( eje_x, resultado_3)
pyplot.show()