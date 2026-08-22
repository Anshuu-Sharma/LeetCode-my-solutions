class Solution {
public:
    int recursion(int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return 1;

        int down = 0;
        int right = 0;
        if(i+1<m) down = recursion(i+1,j,m,n);
        if(j+1<n) right = recursion(i,j+1,m,n);

        return down + right;
    }

    int tabulation(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[m-1][n-1] = 1;
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;
                        int down = 0;
        int right = 0;
        if(i+1<m) down = dp[i+1][j];
        if(j+1<n) right = dp[i][j+1];
        dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        // return recursion(0,0,m,n);
        return tabulation(m, n);
    }
};