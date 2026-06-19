class Solution {
    // Memoization table: -1 means uncalculated, 0 means false, 1 means true
    vector<vector<int>> memo;
    
    bool solve(int i, int j, const string& s1, const string& s2, const string& s3) {
        // Base case: If we have reached the end of both s1 and s2 successfully
        if (i == s1.length() && j == s2.length()) {
            return true;
        }
        
        // Return cached result if already computed
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }
        
        bool ans = false;
        
        // Choice 1: Use a character from s1
        if (i < s1.length() && s1[i] == s3[i + j]) {
            ans = ans || solve(i + 1, j, s1, s2, s3);
        }
        
        // Choice 2: Use a character from s2
        if (j < s2.length() && s2[j] == s3[i + j]) {
            ans = ans || solve(i, j + 1, s1, s2, s3);
        }
        
        // Store the result in memo table and return
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Initial length check
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        // Initialize memoization table with -1
        memo.assign(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        
        // Start recursion from the beginning of both strings
        return solve(0, 0, s1, s2, s3);
    }
};