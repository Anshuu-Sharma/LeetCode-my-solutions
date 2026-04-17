class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n<=2) return 1;

        if(dp[n] != -1) return dp[n];
        int maxProd = 1;
        // int tempProd = 1;
        for(int i = 1; i<=n/2; i++){
            int curr = i * max(n-i, helper(n-i, dp));
            maxProd = max(maxProd, curr);
        }
        return dp[n] = maxProd;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);

    }
};