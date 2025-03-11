class Solution {
public:
    // int recursionHelper(vector<int>& prices, int ind, int buy, int n, int cap, vector<vector<vector<int>>> dp){
    //     if(ind == n || cap ==0) return 0;

    //         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     if(buy){
    //         return max(-prices[ind] + recursionHelper(prices, ind+1, 0, n, cap, dp), 0 + recursionHelper(prices, ind+1, 1, n, cap, dp));
    //     }
    //     return max(prices[ind] + recursionHelper(prices, ind + 1, 1, n, cap-1, dp), 0 + recursionHelper(prices, ind+1, 0, n, cap, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3,-1)));
        // return recursionHelper(prices, 0, 1, n, 2,dp);

        //base case1
        for(int ind = 0; ind<n; ind++){
            for(int buy = 0; buy<=1; buy++){
                dp[ind][buy][0] = 0;
            }
        }
        //base case2
        for(int buy = 0; buy<2; buy++){
            for(int cap = 0; cap<3; cap++){
                dp[n][buy][cap] = 0;
            }
        }

        //main code
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                for(int cap = 1; cap<=2; cap++){
                     if(buy){
           dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
        }
        else{
        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
        }
                }
            }
        }
        return dp[0][1][2];
    }

};