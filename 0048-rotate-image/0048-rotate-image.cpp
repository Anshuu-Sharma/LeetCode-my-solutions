class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0;i<=n-2; i++) {
            for(int j = i+1; j<=n-1;j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        for(int i = 0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};