// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void code(){
    int lenA;
    cin>>lenA;
    
    string strA;
    cin>>strA;
    
    int lenBNC;
    cin>>lenBNC;
    
    string strB;
    cin>>strB;
    
    string stringVD;
    cin>>stringVD;
    
    string beg="";
    string end="";
    
    
    for(int i=0;i<stringVD.size();i++){
        char c=stringVD[i];
        if(c=='V'){
            beg+=strB[i];
        }else{
            end+=strB[i];
        }
    }
    
    reverse(beg.rbegin(),beg.rend());
    
    cout<< beg+strA+end<<endl;
}

int main() {
    
    int numTestCase;
    cin>>numTestCase;
    for(int i=0;i<numTestCase;i++){
        code();
    }

    



    return 0;
}