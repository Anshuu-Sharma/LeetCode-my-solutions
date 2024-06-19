class Solution {
public:

    void markrow(vector<vector<int>>& matrix,int row, int m) {
        for(int j = 0; j<m; j++) {
            if(matrix[row][j] != 0) {
                matrix[row][j] = -1111;
            }
        }
    }

    void markcol(vector<vector<int>>& matrix,int col, int n){
        for(int j = 0; j<n; j++) {
            if(matrix[j][col] != 0) {
                matrix[j][col] = -1111;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        bool ahead = false;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0){
                    markrow(matrix,i,m);
                    markcol(matrix,j,n);
                    ahead = true;
                }
            }
        }
        
        if(ahead == true){
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == -1111) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
};