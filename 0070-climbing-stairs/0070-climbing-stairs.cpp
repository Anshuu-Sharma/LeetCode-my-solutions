class Solution {
public:
    // int helper(int n, vector<int>& dp) {
    //     if(n==0 || n==1) return dp[n] = 1;

    //     if(dp[n] != -1) return dp[n];

    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
    int climbStairs(int n) {
        // if(n==0 || n==1) return 1;

        // int oneStep = climbStairs(n-1);
        // int twoStep = climbStairs(n-2);
        // return oneStep+twoStep;

        vector<int> dp(n+1,-1);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};