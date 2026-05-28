class Solution {
public:
    bool helper(int ind, int n, int target, vector<int>& nums,  vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == n-1) return false;

        if(dp[ind][target] != -1) return dp[ind][target];

        int take = false;
        if(nums[ind] <= target) take = helper(ind+1, n, target - nums[ind], nums, dp);
        int notTake = helper(ind+1, n, target, nums, dp);

        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1) return false;
        target = target/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return helper(0, n, target, nums, dp);
    }
};