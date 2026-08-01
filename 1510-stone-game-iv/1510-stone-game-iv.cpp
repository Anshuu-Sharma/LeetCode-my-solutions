class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                // If taking (k*k) stones leaves the next player in a losing state,
                // the current player can force a win.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // No need to check further moves for state i
                }
            }
        }
        
        return dp[n];
    }
};