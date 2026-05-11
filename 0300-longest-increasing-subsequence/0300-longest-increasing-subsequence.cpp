class Solution {
public:
    int helper(int idx, int n, vector<int>& nums, int prev_idx, vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];

        int take = 0;
        int notTake = 0 + helper(idx+1, n, nums, prev_idx, dp);
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]) take = 1 + helper(idx+1, n, nums, idx, dp);

        return dp[idx][prev_idx+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // prev_idx has range -1 to n-1 and -1 cannot be accomodated in array therefore we shift this by 1 so that it becomes 0 to n but idx is only 0 to n-1 because it doesnt have -1 as its value.
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0, n, nums, -1, dp);
    }
};