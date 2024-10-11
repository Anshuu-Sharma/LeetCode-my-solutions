class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0; // Check for empty grid or row
        
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int firstRow = rowCount, lastRow = -1;
        int firstCol = colCount, lastCol = -1;
        
        // Traverse the grid to find the first and last rows and columns containing 1s
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (grid[i][j] == 1) {
                    firstRow = min(firstRow, i);
                    lastRow = max(lastRow, i);
                    firstCol = min(firstCol, j);
                    lastCol = max(lastCol, j);
                }
            }
        }
        
        // If no '1' was found, return 0
        if (lastRow == -1 || lastCol == -1) return 0;
        
        // The area is determined by the rectangular bounds containing all 1s
        return (lastRow - firstRow + 1) * (lastCol - firstCol + 1);
    }
};
