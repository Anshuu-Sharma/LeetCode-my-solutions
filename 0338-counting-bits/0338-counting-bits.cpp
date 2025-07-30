class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int k = 1;
        for (int i = 1; i <= n; i++) {
            if (i == k) {
                ans[i] = 1;
                k <<= 1;
            } else {
                ans[i] = ans[i - (k >> 1)] + 1;
            }
        }
        return ans;
    }
};