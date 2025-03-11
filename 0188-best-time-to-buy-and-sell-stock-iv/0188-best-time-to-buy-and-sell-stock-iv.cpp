class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int Limitcap = k;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(Limitcap+1,0)));

        // //base case1
        // for(int ind = 0; ind<n; ind++){
        //     for(int buy = 0; buy<=1; buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // //base case2
        // for(int buy = 0; buy<2; buy++){
        //     for(int cap = 0; cap<Limitcap; cap++){
        //         dp[n][buy][cap] = 0;
        //     }
        // }

        //main code
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                for(int cap = 1; cap<=Limitcap; cap++){
                     if(buy){
           dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
        }
        else{
        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
        }
                }
            }
        }
        return dp[0][1][Limitcap];
    }

    
};