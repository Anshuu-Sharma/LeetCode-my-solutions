class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n-2; j++) {
                prefix[i][j] = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            }
        }

        int maxi = INT_MIN;

        for(int i = 0; i<m-2; i++) {
            for(int j = 0; j<n-2; j++) {
                int sum = prefix[i][j] + prefix[i+2][j] + grid[i+1][j+1];
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};