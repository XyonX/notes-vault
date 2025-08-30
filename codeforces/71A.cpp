// Online C++ compiler to run C++ program online

#include <bits/stdc++.h>

using namespace std;


string abv(string s){
    int size=s.size();
    if(size<=10)return s;
    
    string res;
    res+=s[0];
    res+=to_string(size-2);
    res+=s[size-1];
    return res;
}

int main() {

    int num;
    cin>>num;
    vector<string>words;
    for( int i=0;i<num;i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    for(string word :words){
        cout<<abv(word)<<endl;
    }

    return 0;
}