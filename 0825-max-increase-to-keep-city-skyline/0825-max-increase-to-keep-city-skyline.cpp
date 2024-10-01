class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
         int rows = grid.size();
        int cols = grid[0].size();
         vector<int> rowMax(rows, INT_MIN);
        vector<int> colMax(cols, INT_MIN);
    

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            rowMax[i] = max(rowMax[i], grid[i][j]);
            colMax[j] = max(colMax[j], grid[i][j]);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(rowMax[i] < colMax[j]){
                ans+=(rowMax[i] - grid[i][j]);
                grid[i][j] = rowMax[i];
            } 
            else {
                ans+=(colMax[j] - grid[i][j]);
                grid[i][j] = colMax[j];
            }
        }   
    }

    return ans;



    }

};