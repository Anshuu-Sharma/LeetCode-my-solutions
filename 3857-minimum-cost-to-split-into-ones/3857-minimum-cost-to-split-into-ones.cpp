class Solution {
public:
    int minCost(int n) {
        // dp[i] stores the minimum cost to split number i into ones
        // We initialize with 0, which automatically handles our base case: dp[1] = 0
        vector<int> dp(n + 1, 0); 
        
        // Build the table from bottom up starting from 2
        for (int i = 2; i <= n; i++) {
            int current_min = INT_MAX;
            
            // Try all possible splits for the current number 'i'
            for (int j = 1; j <= i / 2; j++) {
                current_min = min(current_min, (j * (i - j)) + dp[j] + dp[i - j]);
            }
            
            dp[i] = current_min;
        }
        
        return dp[n];
    }
};