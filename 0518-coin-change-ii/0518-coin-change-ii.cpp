class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // sort(coins.begin(),coins.end());
        vector<long long unsigned int> prev(amount+1, 0);
        vector<long long unsigned int> curr(amount+1, 0);

        for(int i = 0; i<amount+1; i++){
           prev[i] = (i % coins[0] == 0);
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<amount+1; j++){
                long long unsigned int notTake = prev[j];
                long long unsigned int take = 0;
                if(coins[i] <= j) take = curr[j-coins[i]];
                curr[j] = (take + notTake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};