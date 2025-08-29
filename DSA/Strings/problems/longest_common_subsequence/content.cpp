#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Without memoization (inefficient for large inputs)
int lcs_1(int i, int j, string s1,string s2){
    
    if(i<0 || j<0)return 0;
    
    if(s1[i] == s2[j]){
        return 1+lcs_1(i-1,j-1,s1,s2);
    }
    
    int lh=lcs_1(i-1,j,s1,s2);
    int rh=lcs_1(i,j-1,s1,s2);
    return max(lh,rh);
}

// With memoization (efficient)
int lcs(int i, int j, const string& s1, const string& s2, vector<vector<int>>& dp)
{
    
    if(i<0 || j<0)return 0;
    if(dp[i][j]!= -1)return dp[i][j];
    
    if(s1[i] == s2[j]){
        return dp[i][j]= 1+lcs(i-1,j-1,s1,s2,dp);
    }
    return  dp[i][j]= max(lcs(i-1,j,s1,s2,dp), lcs(i,j-1,s1,s2,dp));
}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
    return lcs(text1.size()-1,text2.size()-1,text1,text2,dp);
}

int main() {
    // Test Case 1: Basic match
    cout << "Test 1: " << longestCommonSubsequence("abcde", "ace") << " (Expected: 3)" << endl;

    // Test Case 2: Identical strings
    cout << "Test 2: " << longestCommonSubsequence("abc", "abc") << " (Expected: 3)" << endl;

    // Test Case 3: No common subsequence
    cout << "Test 3: " << longestCommonSubsequence("abc", "def") << " (Expected: 0)" << endl;

    // Test Case 4: One empty string
    cout << "Test 4: " << longestCommonSubsequence("", "abc") << " (Expected: 0)" << endl;

    // Test Case 5: Both empty strings
    cout << "Test 5: " << longestCommonSubsequence("", "") << " (Expected: 0)" << endl;

    // Test Case 6: Subsequence at the end
    cout << "Test 6: " << longestCommonSubsequence("xyzabc", "abc") << " (Expected: 3)" << endl;

    return 0;
}