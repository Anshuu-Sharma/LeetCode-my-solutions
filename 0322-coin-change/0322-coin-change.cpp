class Solution {
public:
    // int recursionHelper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
        
    //     if(ind == 0){
    //         if(amount % coins[ind] == 0) return dp[ind][amount] = amount/coins[ind];
    //         else return dp[ind][amount] = 1e9;
    //     }

    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int notTake = 0 + recursionHelper(coins, amount, ind-1, dp);
    //     int take = INT_MAX;
    //     if(coins[ind] <= amount) take = 1 + recursionHelper(coins, amount-coins[ind], ind ,dp);
    //     return dp[ind][amount] = min(take, notTake);

    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));
        // int ans = recursionHelper(coins, amount, n-1, dp);
        // return ans>=1e9 ? -1 : ans;

        for(int i = 0; i<amount+1; i++){
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = INT_MAX;
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<amount+1; j++){
                // if(dp[ind][amount] != -1) return dp[ind][amount];
                long long notTake = 0 + dp[i-1][j];
                long long take = INT_MAX;
                if(coins[i] <= j) take = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }
        long long ans =  dp[n-1][amount];
        return ans>=1e9 ? -1 : ans;
    }
};