class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1 && (i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0)) {
                    int r2 = i;
                    int c2 = j;
                    
                    while (r2 + 1 < m && land[r2 + 1][j] == 1) {
                        r2++;
                    }
                    while (c2 + 1 < n && land[i][c2 + 1] == 1) {
                        c2++;
                    }
                    
                    result.push_back({i, j, r2, c2});
                }
            }
        }
        
        return result;
    }
};