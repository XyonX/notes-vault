#include <bits/stdc++.h>
using namespace std;

// Function declaration
int longest_unique_subarray(const vector<int>& arr){
    
    if(arr.size() ==0)return 0;

    int maxLength=INT_MIN;
    map<int,int>freq;
    
    int l=0;
    for(int r=0;r<arr.size();r++){
        
        if(freq.find(arr[r]) != freq.end() && freq[arr[r]]>=l){
            l=freq[arr[r]]+1;
        }
        freq[arr[r]]=r;
        
        maxLength=max(maxLength,r-l+1);
        
    }
    return maxLength;
}