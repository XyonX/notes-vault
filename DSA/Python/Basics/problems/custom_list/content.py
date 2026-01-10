# implementation of custom list class(similar to python list in python)
# FEATURES TO BE IMPLEMENTED
'''
1. CREATE LIST 
2.len(d)
3.append(d)
4.print(d)
.
.
.
11.remove

'''
class MeraList:
    def __init__(self):
        # the capacity of our custom list
        self.size=1;
        # the current number of items in the list 
        self.n=0;
        # create c type array with size = self.size
        # the double underscore __ is used so that subclass doesn't modify it
        # python adds the classname in the beginning of the function name for __
        self.A=self.__create_array(self.size)
    
    # this is a magic function that the len function expects to be defined in the class
    # when we put this class instance in the len function it will call this one
    def __len__(self):
        return self.n
    
    def __create_array(self,capacity):
        # create a c type fixed size static array (also a referential array)
        return (capacity*ctypes.py_object)()
    def append(self,item):
        if self.n==self.size:
            # list is full, resize
            self.__resize(self.size*2)
        # space is available, we can put the item
        self.A[self.n]=item
        self.n=self.n+1
        
    def __resize(self,new_capacity):
        # create a new array with new capacity
        B=self.__create_array(new_capacity)
        # copy elements from old to new array
        
        for i in range(0,self.n):
            B[i]=self.A[i]
        # reassign A
        self.A=B
        self.size=new_capacity
    def __str__(self):
        result=''
        
        for i in range(0,self.n):
            result =result+ str(self.A[i])+','
        return '['+result[:-1]+']'
    def __getitem__(self,index):
        if index>=self.n:
            return  "Index out of range"
        return self.A[index]
    def pop(self):
        if self.n==0:
            return 'Empty List'
            
        el = self.A[self.n-1]
        self.n=self.n-1
        return el
    def clear(self):
        self.n=0;
        self.size=1;
    def insert(self,pos,val):
        if self.size==self.n:
            self.__resize(self.size*2);
        for i in range (self.n,pos,-1):
            self.A[i]=self.A[i-1]
        self.A[pos]=val;
        self.n=self.n+1
    def delete(self,index):
        if index>=self.n:
            return " invalid index !!!"
        for i in range (index,self.n-1):
            self.A[i]=self.A[i+1]
        self.n=self.n-1;
    def remove(self,val):
        index = self.find(val)
        if(type(val) == int):
            #delete
            self.delete(index)
        else:
            return index
        
    
    
            
        
l = MeraList()
print(type(l))
print(len(l))
l.append("hello")
print(len(l))
l.append(True)
print(len(l))
print(l)
print(l[2])
print(l.pop())
l.insert(1,2)
print(l)
l.delete(1)
print(l)