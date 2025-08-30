// Minimum Cost Climbing Stairs (DP)
// Problem: Find the minimum cost to reach the top of the floor where you can start from either step 0 or step 1
// Approach: Bottom-up DP where each step cost includes the minimum of the previous two steps
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive solution (inefficient)
int minCost_rec(int i, vector<int>& cost){
    if(i == 0 or i==1) return cost[i];
    
    return cost[i]+min(minCost_rec(i-1,cost),minCost_rec(i-2,cost));
}

// DP solution with tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n <= 1) return 0;
        
        vector<int>dp(n);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]= cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

// Space optimized DP solution
class SolutionOptimized {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n <= 1) return 0;
        
        int a = cost[0];
        int b = cost[1];
        
        for(int i=2;i<n;i++){
            int current = cost[i] + min(a, b);
            a = b;
            b = current;
        }
        return min(a, b);
    }
};

int main() {
    vector<int> cost1 = {10,15,20};
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    
    Solution sol;
    SolutionOptimized solOpt;
    
    cout<<"Min cost for [10,15,20]: "<<sol.minCostClimbingStairs(cost1)<<endl;
    cout<<"Min cost for [1,100,1,1,1,100,1,1,100,1]: "<<solOpt.minCostClimbingStairs(cost2)<<endl;
    
    return 0;
}