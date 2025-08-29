#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if a string is palindrome
    bool isPalindrome(string s){
        if(s.size()==0 || s.size() ==1)return true;
        for(int i=0;i<s.size()/2;i++){
            if(s[i] != s[s.size()-1-i])return false;
        }
        return true;
    }

    // Version 1: Returns both the string and length (not optimal, exceeds time limit)
    void longestPS(int i,string s,string ss, string& maxString, int& maxLength)
    {
        if(i>=s.size())return ;

        //take the char 
        ss.push_back(s[i]);

        //check if its palindrome
        if(isPalindrome(ss)){
            if(ss.size()>maxLength){
               maxString=ss;
               maxLength=ss.size();
            }
        }

        longestPS(i+1,s,ss,maxString,maxLength);

        //backtrack
        ss.pop_back();

        //moving without taking the current char
        longestPS(i+1,s,ss,maxString,maxLength);
    }
    
    // Version 2: Returns only length (still not optimal, needs memoization)
    int longestPS(int i, string s, string ss)
    {
        if(i == s.size())
            return isPalindrome(ss) ? ss.size() : 0;

        // take s[i]
        ss.push_back(s[i]);
        int l1 = longestPS(i+1, s, ss);
        ss.pop_back();

        // skip s[i]
        int l2 = longestPS(i+1, s, ss);

        return max(l1, l2);
    }
    
    int longestPalindromeSubseq(string s) {
        // Version 1 (returns both string and length)
        string maxString; 
        int maxLength=0;
        longestPS(0,s,"",maxString,maxLength);
        return maxLength;
        
        // Version 2 (returns only length)
        // return longestPS(0,s,"");
    }
};