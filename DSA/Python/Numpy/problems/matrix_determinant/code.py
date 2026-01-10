#this code is for a matrix 
#hopw toi make a matrix 
# matrix is just a list contiane lsit or list of list
#we used a loop to create row from tkaing the input 
# for the dimention we created that mnay row
# we used the rouind func tion to get hte desired 2 decimal precision
#how to calcualte determinat of a array
import numpy

dim = int(input())
mat=[]

for _ in range(dim):
    row = list(map(float,input().split()))
    mat.append(row)

result = numpy.linalg.det(mat)
print(round(result,2))