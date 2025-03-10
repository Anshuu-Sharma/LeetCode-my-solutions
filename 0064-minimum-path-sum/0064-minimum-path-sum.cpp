class Solution {
public:
    // long long recursionHelper(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
    //     if(i==0 && j==0) return grid[0][0];
    //     if(i<0 || j<0) return INT_MAX;

    // if(dp[i][j] != -1) return dp[i][j];
    //     long long up = grid[i][j] + recursionHelper(grid, i-1, j,dp);
    //     long long left = grid[i][j] + recursionHelper(grid, i, j-1, dp);

    //     return dp[i][j] = min(up,left);

    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int up = grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left+=1e9;
                dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};