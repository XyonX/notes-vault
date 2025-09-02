#include <bits/stdc++.h>
using namespace std;

void  lcs(int i1, int i2,const  string & s1,const string &s2, string cs,string& ls){
    
    if(i1 <0 || i2 <0) {
        if(cs.size()>ls.size())
        ls=cs;
        return;
    }


    if(s1[i1]== s2[i2])
    lcs(i1-1,i2-1,s1,s2,cs+s1[i1],ls);

    //didnt matched we open two branch
    lcs(i1,i2-1,s1,s2,cs,ls);
    lcs(i1-1,i2,s1,s2,cs,ls);
}

// Placeholder for the actual function
string longestCommonSubstring(const string& s1, const string& s2){
    
    string ls="";
    lcs(s1.size()-1,s2.size()-1,s1,s2,"",ls);
    reverse(ls.begin(),ls.end());
    return ls;
    
}

int main() {
    // Test 1: Basic overlap
    cout << "Test 1: " << longestCommonSubstring("abcdef", "zabcf") << endl; // Expected: "abc"

    // Test 2: No common substring
    cout << "Test 2: " << longestCommonSubstring("xyz", "abc") << endl; // Expected: ""

    // Test 3: Full match
    cout << "Test 3: " << longestCommonSubstring("hello", "hello") << endl; // Expected: "hello"

    // Test 4: Case sensitivity
    cout << "Test 4: " << longestCommonSubstring("Hello", "hello") << endl; // Expected: "ello" or ""

    // Test 5: Common substring at end
    cout << "Test 5: " << longestCommonSubstring("xyzabc", "123abc") << endl; // Expected: "abc"

    // Test 6: Common substring in middle
    cout << "Test 6: " << longestCommonSubstring("xxabcxx", "yyabczz") << endl; // Expected: "abc"

    // Test 7: Multiple common substrings, longest one
    cout << "Test 7: " << longestCommonSubstring("ababc", "babca") << endl; // Expected: "babc"

    // Test 8: Empty strings
    cout << "Test 8: " << longestCommonSubstring("", "") << endl; // Expected: ""

    // Test 9: One empty string
    cout << "Test 9: " << longestCommonSubstring("abc", "") << endl; // Expected: ""

    // Test 10: Long strings with overlap
    string s1 = "abcdefghijxyz";
    string s2 = "xyzabcdefghij";
    cout << "Test 10: " << longestCommonSubstring(s1, s2) << endl; // Expected: "abcdefghij"
}