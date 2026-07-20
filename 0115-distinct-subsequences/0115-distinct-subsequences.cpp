class Solution {
public:
    // int helper(int ind1, int ind2, int n1, int n2, string s1, string s2, vector<vector<int>>& dp){
    //     if(ind2<0) return 1;
    //     if(ind1<0) return 0;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     if(s1[ind1] == s2[ind2]){
    //         return dp[ind1][ind2]= helper(ind1-1, ind2-1, n1, n2, s1, s2, dp) + helper(ind1-1, ind2, n1, n2, s1, s2, dp);
    //     }

    //     return dp[ind1][ind2]= helper(ind1-1, ind2, n1, n2, s1, s2, dp);
    // }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        vector<vector<unsigned int >> dp(n1+1, vector<unsigned int >(n2+1, 0));

        for(int i = 0; i<n1; i++) dp[i][0] = 1;

        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    dp[ind1][ind2]= dp[ind1-1][ind2-1] + dp[ind1-1][ind2];
                }
                else dp[ind1][ind2] = dp[ind1-1][ind2];
            }
        }
        return dp[n1][n2];

        // return helper(n1-1, n2-1, n1, n2, s, t, dp);
    }
};