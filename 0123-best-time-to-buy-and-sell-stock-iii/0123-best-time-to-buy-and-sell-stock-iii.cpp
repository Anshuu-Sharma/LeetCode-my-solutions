class Solution {
public:
    // int helper(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    //     if(ind == prices.size() || cap == 0) return 0;

    //     if(dp[buy][ind][cap] != -1) return dp[buy][ind][cap];

    //     if(buy){
    //         return dp[buy][ind][cap] = max(-prices[ind] + helper(ind+1, 0, cap, prices, dp), 0 + helper(ind+1, 1, cap, prices, dp));
    //     }
    //     else{
    //         return dp[buy][ind][cap] = max(prices[ind] + helper(ind+1, 1, cap-1, prices, dp), 0 + helper(ind+1, 0, cap, prices, dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(cap+1, 0)));

        // base case already set to 0. so no need to set them exclusively

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int k = 1; k<=cap; k++){
                     if(buy){
                        dp[buy][ind][k] = max(-prices[ind] + dp[!buy][ind+1][k], 0 + dp[buy][ind+1][k]);
                    }
                    else{
                        dp[buy][ind][k] = max(prices[ind] + dp[!buy][ind+1][k-1], 0 + dp[buy][ind+1][k]);
                    }
                }
            }
        }

        return dp[1][0][2];
    }
};