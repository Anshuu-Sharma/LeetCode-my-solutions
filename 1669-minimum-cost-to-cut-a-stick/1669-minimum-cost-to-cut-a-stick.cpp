class Solution {
public:
    // int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    //     if(i>j) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     int mini = INT_MAX;
    //     for(int k = i; k<=j; k++) {
    //         int cost = cuts[j+1] - cuts[i-1] + helper(i, k-1, cuts,dp) + helper(k+1, j, cuts, dp);
    //         mini = min(mini, cost);
    //     }
    //     return dp[i][j] = mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        vector<int> temp = cuts;
        temp.insert(temp.begin(), 0);
        temp.push_back(n);
        sort(temp.begin(), temp.end());
        int c = temp.size();

        vector<vector<long long>> dp(c, vector<long long>(c,0));
        // return helper(1,c-2, temp, dp);

        for(int i = c-1; i>=1; i--) {
            for(int j = i; j<=c-2; j++) {
                long long mini = LONG_MAX;
                for(int k = i; k<=j; k++) {
                    long long cutCost = temp[j+1] - temp[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cutCost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c-2];

    }
};