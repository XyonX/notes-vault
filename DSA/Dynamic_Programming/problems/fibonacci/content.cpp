// Fibonacci Sequence (DP)
// Problem: Calculate the nth Fibonacci number using dynamic programming
// Approach: Bottom-up DP with tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>

using namespace std;

int fibo(int n){
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    cout<<fibo(5)<<endl;
    return 0;
}