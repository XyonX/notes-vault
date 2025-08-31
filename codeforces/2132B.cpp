// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


// n = x + y = x + x * 10^k = x * (1 + 10^k)
//n % (1 + 10^k) == 0

 vector<long long> secretNumber(long long num){
    vector<long long>res;
    for(long long pow10=10;pow10<num;pow10*=10){
        long long denom = 1+pow10;
        if(num%denom==0){
            res.push_back(num/denom);
        }
    }
    return res;
    
}




int main() {

    int numTest;
    cin>>numTest;
    vector<long long>input;
    for(int i=0;i<numTest;i++){
        long long num;
        cin>>num;
        input.push_back(num);
    }
    
    for(int i=0;i<input.size();i++){
        long long num=input[i];
        vector<long long>res=secretNumber(num);
        sort(res.begin(),res.end());
        
        cout << res.size() << endl;
        if (!res.empty()) {
            cout << res[0];
            for (int j = 1; j < res.size(); j++) {
                cout << " " << res[j];
            }
            cout << endl;
        }
    }

    return 0;
}