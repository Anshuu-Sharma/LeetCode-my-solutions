class Solution {
public:
    int helper(int n, int eggs,vector<vector<int>>& dp){
        if(dp[n][eggs] != -1) return dp[n][eggs];
        if(n<=1) return dp[n][eggs] = n;
        if(eggs==1) return dp[n][1] = n;

        int mini = 1e6;
        for(int i = 1; i<=n; i++){
            mini = min(mini, max(helper(i-1, eggs-1, dp), helper(n-i, eggs, dp))+1);
        }
        return dp[n][eggs]=mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3,-1));

        return helper(n, 2, dp);
    }
};