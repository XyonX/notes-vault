// Nth Tribonacci Number (LeetCode 1137)
// Problem: Calculate the nth Tribonacci number where each term is the sum of the three preceding terms
// Approach: Bottom-up DP with three base cases
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};

// Space optimized version
class SolutionOptimized {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        int a = 0, b = 1, c = 1;
        for(int i=3;i<=n;i++){
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
};

int main() {
    Solution sol;
    SolutionOptimized solOpt;
    
    cout<<"Tribonacci(5): "<<sol.tribonacci(5)<<endl;
    cout<<"Tribonacci(25): "<<solOpt.tribonacci(25)<<endl;
    
    return 0;
}