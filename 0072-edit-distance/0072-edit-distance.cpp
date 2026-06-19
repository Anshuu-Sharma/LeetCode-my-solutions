class Solution {
public:
    // int helper(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    //     if(ind1<0) return ind2+1;
    //     if(ind2<0) return ind1+1;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] =  0 + helper(ind1-1, ind2-1, s1, s2,dp);
    //     return dp[ind1][ind2] = min(1+helper(ind1, ind2-1, s1, s2,dp), min(1+helper(ind1-1, ind2, s1, s2,dp), 1+ helper(ind1-1,ind2-1, s1, s2, dp)));

    // }
    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        // return helper(n1-1, n2-1, word1, word2,dp);

        // Base cases
        for(int i = 0; i<=n1; i++) dp[i][0] = i;
        for(int i = 0; i<=n2; i++) dp[0][i] = i;

        for(int ind1 = 1; ind1<=n1; ind1++) {
            for(int ind2 = 1; ind2<=n2; ind2++) {
                if(s1[ind1-1] == s2[ind2-1]) dp[ind1][ind2] =  0 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = min(1+ dp[ind1-1][ind2] , min(1 + dp[ind1][ind2-1], 1 + dp[ind1-1][ind2-1])); 
            }
        } 
        return dp[n1][n2];



    }
};