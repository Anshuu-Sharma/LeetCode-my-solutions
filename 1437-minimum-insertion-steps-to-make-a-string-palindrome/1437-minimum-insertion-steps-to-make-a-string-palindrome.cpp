class Solution {
public:
    int minInsertions(string s) {
        string text1 = s;
        string text2 = s;
        reverse(text2.begin(), text2.end());

        int n1 = text1.size();
        int n2 = n1;

        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);

        // main loop
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                // if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
                if(text1[ind1-1] == text2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];

                else curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return n1 - prev[n2];
    }
};