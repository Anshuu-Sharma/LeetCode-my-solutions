class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    if(i-1 < 0 || grid[i-1][j] == 0) ans++;
                    if(j-1 < 0 || grid[i][j-1] == 0) ans++;
                    if(i+1 == m || grid[i+1][j] == 0) ans++;
                    if(j+1 == n || grid[i][j+1] == 0) ans++; 
                }
            }
        }

        return ans;
    }
};