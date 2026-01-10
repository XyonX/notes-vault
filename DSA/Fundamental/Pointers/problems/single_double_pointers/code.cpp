//single poiner and doubel pointer
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


////01  single pointer THIS APPROACH OF UDPATING PIOINTER INPLACE  WITHOUT DOUBLE POINTER WHIHC EXPECTS A VALID OBKECT
//THIS IS NOTO SAFE AND NOT USED IN PRDUCTION
//SOME CONCEPT OF POINTER
//singel poineer camnt update hte argument param


class demo{
    public:
    int data;
    void display(){
        cout<<"value of data: "<<data<<endl;
    }
};

//taking the pointer so that we can access teh address
//we are noto taking the double pointer and we ar e not planing to update thesouce pointer rather the location the param pointer is poinerintg we are aimimng to update in that addres
//we ar etryibng noto toreturn rather direclty update
void create(demo* ptr){
    demo*obj = new demo();
    (*ptr)=*obj;
}

////02 duble pointer USING DOUBLE POINTER TO UPDATE 
//double pointer can udpate htetargument param

void create_2(demo**ptr){
    //it will update hte poiner directlyu
    *ptr=new demo();
}

int main() {

    demo*ptr = new demo();
    create(ptr);
    ptr->data=10;
    ptr->display();

    return 0;
}