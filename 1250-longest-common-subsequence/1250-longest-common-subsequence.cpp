class Solution {
public:
    // int recursionHelper(string text1, string text2, int ind1, int ind2, vector<vector<int>> dp){
    //     if(ind1==0 || ind2==0) return 0;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    //     if(text1[ind1-1] == text2[ind2-1]) return dp[ind1][ind2] = 1 + recursionHelper(text1, text2, ind1-1, ind2-1, dp);

    //     return dp[ind1][ind2] = 0 + max(recursionHelper(text1, text2, ind1-1, ind2, dp), recursionHelper(text1, text2, ind1, ind2-1, dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);

        // return recursionHelper(text1, text2, n1, n2, dp);


        // Base case
        // for(int i = 0; i<=n2; i++){
        //     dp[0][i] = 0;
        // }
        // for(int i = 0; i<=n1; i++){
        //     dp[i][0] = 0;
        // }

        // main loop
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                // if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
                if(text1[ind1-1] == text2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];

                else curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
};