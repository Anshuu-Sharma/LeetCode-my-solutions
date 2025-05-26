class Solution {
public:
    // int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    //     if(m<0 || n<0) return 0;
    //     if(obstacleGrid[m][n] == 1) return 0;
    //     if(m==0 && n==0) return 1;

    //     int up = helper(m-1,n,obstacleGrid, dp);
    //     int left = helper(m,n-1,obstacleGrid, dp);

    //     return dp[m][n] =  up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else if(i==0 && j==0) curr[j] = 1;
                else {
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};