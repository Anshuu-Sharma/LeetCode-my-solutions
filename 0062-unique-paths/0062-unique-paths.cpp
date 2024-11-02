class Solution {
public:

    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    int up = 0;
                    int left = 0;

                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }

            }
        }
        return dp[m-1][n-1];

    }
    // MEMOIZATION METHOD
    // int dp_helper(int n, int m, vector<vector<int>>& dp){
    //     if(n == 0 && m == 0) return 1;
    //     if(n < 0 || m < 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];
    //     int up = dp_helper(n-1, m, dp);
    //     int left = dp_helper(n, m-1, dp);
        
    //     return dp[n][m] = up + left;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return dp_helper(m-1, n-1, dp);
    // }

    // RECURSION METHOD
    // int dp_helper(int n, int m){
    //     if(n == 0 && m == 0) return 1;
    //     if(n < 0 || m < 0) return 0;

    //     int up = dp_helper(n-1, m);
    //     int left = dp_helper(n, m-1);
        
    //     return up + left;
    // }
    // int uniquePaths(int m, int n) {
    //     return dp_helper(m-1,n-1);
    // }
};