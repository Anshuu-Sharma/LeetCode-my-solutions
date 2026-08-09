class Solution {
public:
    int countSubstrings(string s) {
    int n = s.length();
    vector<int> dp(n, 1); // dp[j] represents palindrome status of current s[i..j]
    int cnt = n;           // count all single chars upfront

    for (int i = n - 2; i >= 0; i--) {
        // iterate j from right to left to avoid overwriting dp[j-1]
        // which still holds dp[i+1][j-1] from the previous outer iteration
        for (int j = n - 1; j >= i + 1; j--) {
            if (s[i] == s[j])
                dp[j] = dp[j - 1]; // reuse inner result before it's overwritten
            else
                dp[j] = 0;
            cnt += dp[j];
        }
    }
    return cnt;
    }
};