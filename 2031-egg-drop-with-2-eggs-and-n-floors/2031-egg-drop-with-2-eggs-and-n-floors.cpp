class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));

        // Base case
        for (int j = 1; j <= n; j++) {
            dp[1][j] = j;
        }

        // Filling the table for 2 eggs
        for (int j = 1; j <= n; j++) {
            dp[2][j] = 1e9; 
            for (int x = 1; x <= j; x++) {
                dp[2][j] = min(dp[2][j], 1 + max(dp[1][x - 1], dp[2][j - x]));
            }
        }

        return dp[2][n];
    }
};
