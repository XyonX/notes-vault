#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    Shape(){};
    virtual float area (){
        cout<<"are of shape";
        return  0;
    };
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
};

class Circle : public Shape {
    int radius;
public:
    Circle(int r){
        radius=r;
    }
    virtual float area ()override {
        cout<<"area of circle"<<3.142*radius*radius;
        return 3.142*radius*radius;
    }
};

int main() {
    Rectangle  r1(5,4);
    r1.area();
    Circle c1(3);
    c1.area();
    return 0;
}