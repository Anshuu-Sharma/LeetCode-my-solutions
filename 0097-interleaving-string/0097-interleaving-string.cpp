class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // If combined lengths don't match, it's impossible outright
        if (m + n != s3.length()) return false;
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // BASE CASES
        
        // 1. Both strings are empty
        dp[0][0] = true;
        
        // 2. s2 is empty: Can s1 alone form the beginning of s3?
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        
        // 3. s1 is empty: Can s2 alone form the beginning of s3?
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        // ==========================================
        //               MAIN DP LOOP
        // ==========================================
        
        // Start from 1 since the 0th row and column are already processed
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                // We can reach the current state either by:
                // Taking a char from s1 (if it matches) OR taking a char from s2 (if it matches)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dp[m][n];
    }
};