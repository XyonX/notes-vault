#a bit of math refresher a polynomial is a expression of x start with a const from right ten we add x^i+1 as we go left
#like ax^2+bx+c for degree 2 and ax^3+bx^2+cx+d
#now we evaluate hte piolynomial we need any valye of x for whihc we wnatth hvlaue of the overall expresssion
#in numpy wehave the polyval which takes the coeffeindt as array and the value of x to evaluate 
#in this code we learned how to use soplit to make list from  space separated strring 
#how to use map fucntion
#and how to calcualtei poilynomial using numpy

import numpy

inp = input()                     # Reads a line like '1.1 2 3'
x = float(input())                # Reads x value like 0
list1 = inp.split()               # ['1.1', '2', '3']
coefficient = list(map(float, list1))  # [1.1, 2.0, 3.0]
result = numpy.polyval(coefficient, x)  # Evaluates polynomial at x
print(result)