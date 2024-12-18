class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(),0);

        for(int i = 0;i < prices.size(); i++){
            int j = i + 1;
            ans[i] = prices[i];
            while(j<prices.size()){
                if(prices[j] <= prices[i]) {
                    ans[i] = prices[i] - prices[j]; 
                    break;
                }
                else j++;
            }
        }
        return ans;
    }
};