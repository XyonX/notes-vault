#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Recursive approach without memoization (inefficient for large inputs)
int lcs_rec(string s1, string s2, int i1, int i2){
    if(i1 < 0 || i2 < 0) return 0;
    
    // The characters match so we move both pointers
    if(s1[i1] == s2[i2]){
        return 1 + lcs_rec(s1, s2, i1-1, i2-1);
    }
    
    return max(lcs_rec(s1, s2, i1, i2-1), lcs_rec(s1, s2, i1-1, i2));
}

// Dynamic Programming approach with memoization
int lcs_dp(string s1, string s2, int i1, int i2, vector<vector<int>>& dp){
    if(i1 < 0 || i2 < 0) return 0;
    
    // Check in dp if already computed
    if(dp[i1][i2] != -1) return dp[i1][i2];
    
    // The characters match so we move both pointers
    if(s1[i1] == s2[i2]){
        return dp[i1][i2] = 1 + lcs_dp(s1, s2, i1-1, i2-1, dp);
    }
    
    return dp[i1][i2] = max(lcs_dp(s1, s2, i1, i2-1, dp), lcs_dp(s1, s2, i1-1, i2, dp));
}

// Wrapper function for DP approach
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return lcs_dp(text1, text2, text1.size() - 1, text2.size() - 1, dp);
}

int main() {
    vector<pair<string, string>> testCases = {
        {"abcde", "ace"},       // Expected LCS length: 3 ("ace")
        {"abc", "abc"},         // Expected LCS length: 3 ("abc")
        {"abc", "def"},         // Expected LCS length: 0 (no common subsequence)
        {"aggtab", "gxtxayb"},  // Expected LCS length: 4 ("gtab")
        {"", "abc"},            // Expected LCS length: 0 (empty string)
        {"abc", ""}             // Expected LCS length: 0 (empty string)
    };
    
    cout << "=== Recursive Approach (Inefficient) ===" << endl;
    for (auto &[s1, s2] : testCases) {
        int result = lcs_rec(s1, s2, s1.size() - 1, s2.size() - 1);
        cout << "LCS(\"" << s1 << "\", \"" << s2 << "\") = " << result << endl;
    }
    
    cout << "\n=== Dynamic Programming Approach (Efficient) ===" << endl;
    for (auto &[s1, s2] : testCases) {
        int result = longestCommonSubsequence(s1, s2);
        cout << "LCS(\"" << s1 << "\", \"" << s2 << "\") = " << result << endl;
    }

    return 0;
}