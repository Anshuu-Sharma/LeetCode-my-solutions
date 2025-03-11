class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        dp[n][0] = dp[n][1] = 0;

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                long profit = 0;

                if(buy){
            if(dp[ind][buy] != -1)
            {
                return dp[ind][buy];
            }
            else{
             profit = max(-prices[ind] + dp[ind+1][0],
                        0 + dp[ind+1][buy]);
            }
        } 
        else{
            if(dp[ind][buy] != -1){
                return dp[ind][buy];
            }
            else{
             profit = max(prices[ind] - fee + dp[ind+1][1],
            0 + dp[ind+1][0]);
            }
        }
            dp[ind][buy] = profit;
            }
        }
        return dp[0][1];

    }
};