class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 0)return dp[0] = 0;
        if(n == 1)return dp[1] = 1;

        if(dp[n] == 0){
            dp[n] = helper(n-1,dp) + helper(n-2, dp);
        }
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,0);
        return helper(n,dp);
    }
};