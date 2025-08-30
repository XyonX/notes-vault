// Climbing Stairs (LeetCode 70)
// Problem: Count the number of ways to reach the nth stair if you can climb either 1 or 2 stairs at a time
// Approach: Similar to Fibonacci, bottom-up DP
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>

using namespace std;

int climbingStairs(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    cout<<"Ways to climb 5 stairs: "<<sol.climbStairs(5)<<endl;
    return 0;
}