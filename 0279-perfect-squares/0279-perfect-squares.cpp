class Solution {
public:
    int numSquares(int n) {
        int limit = sqrt(n);
        vector<vector<int>> dp(limit + 2, vector<int>(n + 1, 1e9));
        
        for (int num = 0; num <= limit + 1; ++num) {
            dp[num][0] = 0;
        }
        
        for (int num = limit; num >= 1; --num) {
            for (int target = 1; target <= n; ++target) {
                int take = 1e9;
                if (num * num <= target) {
                    take = 1 + dp[num][target - (num * num)];
                }
                int notTake = dp[num + 1][target];
                
                dp[num][target] = min(take, notTake);
            }
        }
        
        return dp[1][n];
    }
};