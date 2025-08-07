class Solution {
public:
    int helper(int r, int c,  vector<vector<int>>& vis,  vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        vis[r][c] = 1;

        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int len = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc] > matrix[r][c]){
                len = max(len, 1 + helper(nr, nc, vis, matrix, dp));
            }
        }
        return dp[r][c] = len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++) {
                if(!vis[i][j]) {
                    maxi = max(maxi, helper(i, j, vis, matrix, dp));
                }
            }
        }
        return maxi;
    }
};