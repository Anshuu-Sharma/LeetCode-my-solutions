class Solution {
public:
    // int recursionHelper(vector<vector<int>>& matrix, int i , int j, int n, vector<vector<int>>& dp){
    //     if (j < 0 || j >= n) return INT_MAX; // Prevent out-of-bounds access
    //     if (i == 0) return dp[i][j] =  matrix[0][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int straight = recursionHelper(matrix, i - 1, j, n, dp);
    //     int leftDiag = recursionHelper(matrix, i - 1, j - 1, n, dp);
    //     int rightDiag = recursionHelper(matrix, i - 1, j + 1, n, dp);

    //     // Only add matrix[i][j] if it does not cause overflow
    //     if (straight != INT_MAX) straight += matrix[i][j];
    //     if (leftDiag != INT_MAX) leftDiag += matrix[i][j];
    //     if (rightDiag != INT_MAX) rightDiag += matrix[i][j];

    //     return dp[i][j] = min(straight, min(leftDiag, rightDiag));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        vector<int> prev(n,0);
        vector<int> curr(n,0);

        //Base case
        for(int i = 0; i<n; i++){
            prev[i] = matrix[0][i];
        }

        // Main code
        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                int straight = INT_MAX;
                int leftDiag = INT_MAX;
                int rightDiag = INT_MAX;
                 straight = matrix[i][j] + prev[j];
                if(j-1 >= 0)  leftDiag = matrix[i][j] + prev[j-1];
                if(j+1 < n)  rightDiag = matrix[i][j] + prev[j+1];
                curr[j] = min(straight, min(leftDiag, rightDiag));
            }
            prev = curr;
        }

        //Finding the minimum value path
        int mini = prev[0]; // leting any arbitrary value first
        for(int i = 1; i<n; i++){  
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};
