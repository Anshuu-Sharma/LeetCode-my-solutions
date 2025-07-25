class Solution {
 public:
 //KNK
  int maximumLength(vector<int>& nums, int k) {
    vector<vector<int>> dp(k, vector<int>(k));
    for (const int x : nums)
      for (int y = 0; y < k; ++y)
        dp[x % k][y] = dp[y][x % k] + 1;

    return accumulate(dp.begin(), dp.end(), 0,
                      [](int acc, const vector<int>& row) {
      return max(acc, ranges::max(row));
    });
  }
};
