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

        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        // base case
        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }

        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=target; j++){
                // if(dp[i][j] != -1) continue;
                
            bool notTake = dp[i-1][j];
            bool take = false;
            if(nums[i] <= j){
                take = dp[i-1][j - nums[i]];
            }
            
            dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][target];

        // return helper(0, n, target, nums, dp);
    }
};