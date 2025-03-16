class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        
        reverse(t.begin(), t.end());

        string text1 = s;
        string text2 = t;
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);

        // main loop
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                if(text1[ind1-1] == text2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];

                else curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }   
};