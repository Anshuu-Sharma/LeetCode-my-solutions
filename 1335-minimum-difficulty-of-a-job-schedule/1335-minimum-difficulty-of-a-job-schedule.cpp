class Solution {
private:
    int solve(vector<int>& jobDifficulty, int n, int idx, int d, vector<vector<int>>& memo) {
        // Base case: If we reach the last day, all remaining jobs must be done today
        if (d == 1) {
            int maxDiff = 0;
            for (int i = idx; i < n; ++i) {
                maxDiff = max(maxDiff, jobDifficulty[i]);
            }
            return maxDiff;
        }

        // Return memoized result if already computed
        if (memo[idx][d] != -1) {
            return memo[idx][d];
        }

        int minTotalDifficulty = INT_MAX;
        int maxDiffToday = 0;

        // Try ending today's work at any index j, leaving enough jobs for remaining d - 1 days
        for (int j = idx; j <= n - d; ++j) {
            maxDiffToday = max(maxDiffToday, jobDifficulty[j]);
            
            // Recursively calculate difficulty for remaining jobs and days
            int remainingDiff = solve(jobDifficulty, n, j + 1, d - 1, memo);
            
            minTotalDifficulty = min(minTotalDifficulty, maxDiffToday + remainingDiff);
        }

        // Cache and return the result
        return memo[idx][d] = minTotalDifficulty;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // Impossible if fewer jobs than days
        if (n < d) return -1;
        
        // Memoization table initialized to -1: memo[idx][days_left]
        vector<vector<int>> memo(n, vector<int>(d + 1, -1));
        
        return solve(jobDifficulty, n, 0, d, memo);
    }
};