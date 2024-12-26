class Solution {
 public:
 //KNK
  int findTargetSumWays(vector<int>& nums, int target) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 == 1)
      return 0;
    return knapsack(nums, (sum + target) / 2);
  }

 private:
  int knapsack(const vector<int>& nums, int target) {
    const int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      const int num = nums[i - 1];
      for (int j = 0; j <= target; ++j)
        if (j < num)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
    }

    return dp[n][target];
  }
};