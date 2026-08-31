class Solution {
public:
    int maximumAmount(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), neg_inf = -(1e9);
        int dp[n][m][3]; 
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                dp[i][j][0] = neg_inf, dp[i][j][2] = neg_inf, dp[i][j][1] = neg_inf;
            }
        }
        // STATE: dp[i][j] = maximum profit to reach i, j
        // base case: (0, 0) maximum profit to reach 0, 0 is g[0][0]
        dp[0][0][0] = g[0][0];
        if(g[0][0] < 0) dp[0][0][1] = 0;
        // dp[0][0][1] = g[0][0] < 0 ? 0 : ;
        // we can either go right or down
        // TRANSITION: dp[i][j] = max(dp[i - 1][j] + g[i][j], dp[i][j - 1] + g[i][j])
        // we can
        for(int i = 0; i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 && j == 0) continue;
                for(int k = 0;k < 3;k++) {
                    if(g[i][j] < 0) {
                        if(i > 0) {
                            // don't neutralise him
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + g[i][j]);
                            // neutralise him
                            if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                        }
                        if(j > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + g[i][j]);
                            if(k >0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                        }
                    } else {
                        if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + g[i][j]);
                        if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + g[i][j]);
                    }
                }
            }
        }
        return max(dp[n - 1][m - 1][0], max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]));
    }
};