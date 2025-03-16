class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);

        // LCS
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){

                if(word1[ind1-1] == word2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];

                else curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        int lcs = prev[n2];
        return n1-lcs + n2 - lcs;
    }
};