class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
       vector<vector<int>> diff1(grid.size(), vector<int>(grid[0].size()));
        vector<int> oneRow(rows,0);
        vector<int> oneCol(cols,0);
        vector<int> zeroRow(rows,0);
        vector<int> zeroCol(cols,0);
       
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[i].size(); j++)
            {
                if(grid[i][j]){
                    oneCol[j]++;
                    oneRow[i]++;
                }
                if(grid[i][j] == 0){
                    zeroCol[j]++;
                    zeroRow[i]++;
                }
            }
        }

        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[i].size(); j++)
            {
                diff1[i][j] = oneRow[i] + oneCol[j] - zeroCol[j] - zeroRow[i]; 
            }
        }
        return diff1;

    }
};