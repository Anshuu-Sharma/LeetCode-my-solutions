class Solution {
public:
//     int helper(int n, vector<int>& dp){
// if (n==0 || n==1) return 1;

//         if(dp[n]!= -1) return dp[n];
//         int oneStep = helper(n-1, dp);
//         int twoStep = helper(n-2,dp);

//         return dp[n] = oneStep + twoStep;
//     }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1); 
        dp[0]= 1; dp[1] = 1; 
        for(int i = 2; i<=n; i++){
             dp[i] = dp[i-1] + dp[i-2]; 
        }
        // return helper(n, dp);
        return dp[n];
    }
};