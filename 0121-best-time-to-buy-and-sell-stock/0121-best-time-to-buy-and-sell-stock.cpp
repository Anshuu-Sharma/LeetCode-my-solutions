class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        for(int i = 1; i<prices.size(); i++) {  
            if(mini >= prices[i]) mini = prices[i];
            else maxProfit = max(maxProfit, (prices[i]- mini));
        }
        return maxProfit;
    }
};