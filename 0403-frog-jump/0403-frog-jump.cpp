class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        for (int jump = 0; jump <= n; ++jump)
            dp[n - 1][jump] = true;                 // base: last stone = win

        unordered_map<int,int> mpp;
        for (int i = 0; i < stones.size(); ++i) mpp[stones[i]] = i;

        for (int pos = n - 2; pos >= 0; --pos) {
            for (int jump = n; jump >= 0; --jump) {
                for (int k = -1; k <= 1; ++k) {
                    int nextJump = jump + k;
                    if (nextJump <= 0 || nextJump > n) continue;
                    auto it = mpp.find(stones[pos] + nextJump);
                    if (it != mpp.end() && dp[it->second][nextJump])
                        dp[pos][jump] = true;
                }
            }
        }
        return dp[0][0];
    }
};