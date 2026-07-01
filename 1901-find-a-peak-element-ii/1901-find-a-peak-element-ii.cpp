class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Step 1: Find the maximum element in the current 'mid' column
            int max_row = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[max_row][mid]) {
                    max_row = i;
                }
            }
            
            // Step 2: Check the left and right neighbors of that max element
            int left_val = (mid - 1 >= 0) ? mat[max_row][mid - 1] : -1;
            int right_val = (mid + 1 < n) ? mat[max_row][mid + 1] : -1;
            
            // Step 3: Determine the next move
            if (mat[max_row][mid] > left_val && mat[max_row][mid] > right_val) {
                return {max_row, mid}; // Found the peak
            } 
            else if (left_val > mat[max_row][mid]) {
                high = mid - 1;        // Peak exists in the left half
            } 
            else {
                low = mid + 1;         // Peak exists in the right half
            }
        }
        
        return {-1, -1}; // Fallback (should not be reached given problem constraints)
    }
};