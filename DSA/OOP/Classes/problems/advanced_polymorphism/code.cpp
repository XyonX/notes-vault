

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//in this code we implemented oeprator overlaoding with  inheritence 
//polymorphism operaotr overlaoding
//this is the base shape class 
//we only doing hte operaor overlaoding in the base class
//but we are creaging a virtual add fucntiion for each derived class to implemnt
//
class Shape {
   
    public:
     Shape(){};
    virtual float area (){
        cout<<"are of shape";
        return  0;
    };
    
     virtual Shape* add(Shape* other)=0;
    
    Shape* operator + (Shape* other){
        return this->add(other);
    }
    
    
 
};


class Rectangle :public Shape{
    
    int width,height;
    public:
    Rectangle(int w,int h){
       width=w;
       height=h;
    }
    virtual float area () override {
        cout<<"are of tirangle"<<width*height<<endl;
        return width*height;
    }
    virtual Shape* add (Shape* other)override{
        Rectangle* r1 = dynamic_cast<Rectangle*>(other);
        return new Rectangle(width+r1->width,height+r1->height);
    }
    
};

class Circle : public Shape {
        int radius;


    public:
        Circle(int r)
{
    radius=r;
}
    
    virtual float area ()override {
        cout<<"area of circle"<<3.142*radius*radius;
        return 3.142*radius*radius;
    }
    
    virtual Shape* add (Shape* other)override{
        
        Circle * c1=dynamic_cast<Circle*>(other);
        return new Circle(radius+c1->radius);
    }
    
};
int main() {
    // Create and test individual areas
    Rectangle r1(5, 4);
    r1.area(); // area of rectangle: 20

    Circle c1(3);
    c1.area(); // area of circle: ~28.278

    cout << "\n---- Testing Rectangle + Rectangle ----\n";
    Shape* r2 = new Rectangle(2, 3);
    Shape* result1 = r1 + r2; // Rectangle + Rectangle
    result1->area(); // Expect area of Rectangle(7,7) = 49

    cout << "\n---- Testing Circle + Circle ----\n";
    Shape* c2 = new Circle(4);
    Shape* result2 = c1 + c2; // Circle + Circle
    result2->area(); // Expect area of Circle(7)

    cout << "\n---- Testing Rectangle + Circle (should throw error) ----\n";
    try {
        Shape* invalid = r1 + c2; // Mixing types, should fail
        invalid->area(); // Should not get here
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Clean up dynamically allocated memory
    delete r2;
    delete result1;
    delete c2;
    delete result2;

    return 0;
}
