class Solution {
public:
    // int recursionHelper(vector<int>& cuts, int i, int j,vector<vector<int>> dp){
    //     if(i>j) return 0;

    //     int mini = INT_MAX;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     for(int ind = i; ind<=j; ind++){
    //         int cost = (cuts[j+1] - cuts[i-1]) + recursionHelper(cuts, i,ind-1, dp) + recursionHelper(cuts, ind+1, j,dp);

    //         mini = min(mini, cost);
    //     }
    //     return dp[i][j] = mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c = cuts.size();
        vector<vector<long long>> dp(c, vector<long long>(c,0));
        // return recursionHelper(cuts, 1, c-2, dp);

        for(int i = c-2; i>=1; i--){
            for(int j = i; j<=c-2; j++){
                long long mini = LONG_MAX;
                    for(int ind = i; ind<=j; ind++){
                    long long cost = (cuts[j+1] - cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];

                    mini = min(mini, cost);
                }
                 dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }
};