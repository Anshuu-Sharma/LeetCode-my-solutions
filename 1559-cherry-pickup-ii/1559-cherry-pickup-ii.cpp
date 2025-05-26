class Solution {
public:
//     int helper(int r, int c1, int c2, vector<vector<int>>& grid, int rows, int cols,  vector<vector<vector<int>>>& dp) {
//         if(c2<0 || c2>=cols || c1<0 || c1>=cols) return -1e9;

//         if(r==rows-1) {
//             if(c1==c2) {
//                 return grid[r][c1];
//             }
//             else return grid[r][c1] + grid[r][c2];
//         }

//         if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
//         int maxi = -1e9;
//         for(int dj1 = -1; dj1<=1;  dj1++) {
//             for(int dj2 = -1; dj2<=1; dj2++) {
//                 if(c1==c2){
//                      maxi = max(maxi, grid[r][c1] + helper(r+1, c1+dj1, c2+dj2, grid, rows, cols,dp));
//                 }
//                 else {
//                      maxi = max(maxi, grid[r][c1] + grid[r][c2] + helper(r+1, c1+dj1, c2+dj2,grid, rows, cols,dp));
//                 }
//             }
//         }
//         return dp[r][c1][c2] = maxi;
// }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols,vector<int>(cols,-1)));

        // Base case
        for(int c1 = 0; c1<cols; c1++) {
            for(int c2 = 0; c2<cols; c2++) {
                if(c1==c2)  dp[rows-1][c1][c2] = grid[rows-1][c1];
                else dp[rows-1][c1][c2] = grid[rows-1][c1] + grid[rows-1][c2];
            }
        }

        for(int r = rows-2; r>=0; r--){
             for(int c1 = 0; c1<cols; c1++) {
                for(int c2 = 0 ; c2<cols; c2++) {
                    int maxi = -1e9;
                   for(int dj1 = -1; dj1<=1;  dj1++) {
                        for(int dj2 = -1; dj2<=1; dj2++) {
                            if(c1+dj1>=0 && c2+dj2>=0 && c1+dj1<cols && c2+dj2<cols){
                                   if(c1==c2){
                                maxi = max(maxi, (grid[r][c1] + dp[r+1][c1+dj1][c2+dj2]));
                            }
                            else {
                                 maxi = max(maxi, grid[r][c1] + grid[r][c2] + dp[r+1][c1+dj1][c2+dj2]);
                            }
                            }
                         
                        }
                    }
                    dp[r][c1][c2] = maxi;
                }
            }
        }
        return dp[0][0][cols-1];

    }
};