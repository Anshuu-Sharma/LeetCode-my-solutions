class Solution {
public:
    // // recursion approach & memoization
    // bool helper(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    //     if(ind1<0 && ind2<0) return true;
    //     if(ind1>=0 && ind2<0) return false; 
    //     if(ind1<0 && ind2>=0) {
    //         while(ind2>=0) {
    //             if(s2[ind2] != '*') return false;
    //             ind2--;
    //         }
    //         return true;
    //     }


    //     if(s1[ind1]==s2[ind2] || s2[ind2] == '?') return dp[ind1][ind2] = helper(ind1-1, ind2-1, s1, s2,dp);

    //     if(s2[ind2] == '*') {
    //         return dp[ind1][ind2] = helper(ind1, ind2-1, s1, s2, dp) || helper(ind1-1, ind2, s1, s2, dp);
    //     }
    //     return dp[ind1][ind2] = false;
    // }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // return helper(n1-1, n2-1, s, p, dp);

        dp[0][0] = 1;
        int notStart = 0;
        for(int i = 1; i<=n2; i++) {
            if(notStart == 1 || p[i-1] != '*') {
                dp[0][i] = 0, notStart = 1;
            }
            else dp[0][i] = 1;
        }

        for(int ind1 = 1; ind1<=n1; ind1++) {
            for(int ind2 = 1; ind2<=n2; ind2++) {
                if(s[ind1-1]==p[ind2-1] || p[ind2-1] == '?')  dp[ind1][ind2] = dp[ind1-1][ind2-1];

                else if(p[ind2-1] == '*') {
                     dp[ind1][ind2] = dp[ind1][ind2-1] ||dp[ind1-1][ind2];
                }
                else dp[ind1][ind2] = 0;
            }
        }
        return dp[n1][n2];

    }
};