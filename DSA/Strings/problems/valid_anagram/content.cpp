#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool validAnagram(string s1,string s2){
    
    if(s1.size()!=s2.size())return false;
    
    vector<int>arr(26,0);
    
    int s =s1.size();
    
    for(int i=0;i<s;i++){
        if (!isalpha(s1[i]) || !isalpha(s2[i])) return false;
        arr[tolower(s1[i])-'a']++;
        arr[tolower(s2[i])-'a']--;
    }
    
    for(int i=0;i<26;i++){
        if(arr[i]!=0)return false;
    }
    return true;
}