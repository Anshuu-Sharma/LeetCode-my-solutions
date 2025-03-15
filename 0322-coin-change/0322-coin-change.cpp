class Solution {
public:
    int recursionHelper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
        
        if(ind == 0){
            if(amount % coins[ind] == 0) return dp[ind][amount] = amount/coins[ind];
            else return dp[ind][amount] = 1e9;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = 0 + recursionHelper(coins, amount, ind-1, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + recursionHelper(coins, amount-coins[ind], ind ,dp);
        return dp[ind][amount] = min(take, notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = recursionHelper(coins, amount, n-1, dp);
        return ans>=1e9 ? -1 : ans;
    }
};