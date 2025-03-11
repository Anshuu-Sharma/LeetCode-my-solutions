class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int boughtPrice = prices[0];

        for(int i = 1; i<prices.size(); i++){
            int currProfit = prices[i] - boughtPrice;
            maxi = max(maxi, currProfit);
            boughtPrice = min(boughtPrice, prices[i]);
        }
        return maxi;
    }
};