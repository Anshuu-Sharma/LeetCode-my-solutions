class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // Impossible if fewer jobs than days
        if (n < d) return -1;

        // dp[i][day]: min difficulty to schedule jobs from index i to n-1 in 'day' days
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, 1e9));

        // Base Case: 1 day remaining (day = 1)
        int maxDiff = 0;
        for (int i = n - 1; i >= 0; --i) {
            maxDiff = max(maxDiff, jobDifficulty[i]);
            dp[i][1] = maxDiff;
        }

        // Fill table for remaining days (from 2 up to d)
        for (int day = 2; day <= d; ++day) {
            // Index i must leave at least (day - 1) jobs for subsequent days
            for (int i = 0; i <= n - day; ++i) {
                int maxDiffToday = 0;

                // Try partitioning today's work at index j
                for (int j = i; j <= n - day; ++j) {
                    maxDiffToday = max(maxDiffToday, jobDifficulty[j]);
                    dp[i][day] = min(dp[i][day], maxDiffToday + dp[j + 1][day - 1]);
                }
            }
        }

        return dp[0][d];
    }
};