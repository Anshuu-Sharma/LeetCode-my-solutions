class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // dp[i][j] will store the minimum delete sum for s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize base case: s2 is empty
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        // Initialize base case: s1 is empty
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    // Characters match, no deletion cost added
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Characters don't match, take the minimum of deleting from s1 or s2
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], 
                                   dp[i][j-1] + s2[j-1]);
                }
            }
        }
        
        // The bottom-right cell contains the answer for the full strings
        return dp[m][n];
    }
};