class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);  

        for (int i = n - 1; i >= 0; i--) {
            long long notTake = dp[i + 1];
            long long take = questions[i][0];  
            
            int nextIdx = i + 1 + questions[i][1];  
            if (nextIdx < n) {
                take += dp[nextIdx];
            }
            
            dp[i] = max(take, notTake);  
        }

        return dp[0];  
    }
};
