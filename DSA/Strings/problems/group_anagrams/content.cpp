#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if(strs.size()==0)return {};
    
    map<string,vector<string>>mp;
    
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>>res;
    
    for(pair<string,vector<string>>p : mp){
        res.push_back(p.second);
    }
    return res;
    
}

// Helper function to display grouped anagrams
void displayStrings(const std::vector<std::string>& vec, const std::string& prefix = "", const std::string& separator = "\n") {
    for (const auto& str : vec) {
        std::cout << prefix << str << separator;
    }
}

int main() {
    vector<string> chars = {
        "abc", "bca", "cab", // same letters, different order
        "xyz", "zyx",        // same letters, reversed
        "mno", "onm",        // another shared set
        "def", "ghi", "jkl"  // unique ones
    };
    vector<vector<string>>res=groupAnagrams(chars);
    
    for(auto s :res){
        cout<<"grouped: "<<endl;
        displayStrings(s);
    }
    
    return 0;
}