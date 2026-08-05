class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int Limitcap = k;
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k+1,0));
        vector<vector<int>> curr(2, vector<int>(k+1,0));

        //main code
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                for(int cap = 1; cap<=Limitcap; cap++){
                     if(buy){
                curr[buy][cap] = max(-prices[ind] + prev[0][cap], 0 + prev[1][cap]);
        }
        else{
            curr[buy][cap] = max(prices[ind] + prev[1][cap-1], 0 + prev[0][cap]);
        }
                }
            }
            prev = curr;
        }
        return prev[1][Limitcap];
    }

    
};