class Solution {
public:
    int helper(int n, int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){
            profit = max(
                -prices[idx] + helper(n, idx+1, 0, prices, dp),
                0 + helper(n, idx+1, 1, prices, dp)
            );
        } 

        else{
            profit = max(
                prices[idx] + helper(n, idx + 1, 1, prices, dp),
                0 + helper(n, idx + 1, 0, prices, dp)
            );
        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(n, 0, 1, prices, dp);
    }
};