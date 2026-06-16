class Solution {
public:
    int helper(int ind, int n, vector<int>& nums, vector<int>& dp){
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        int take = nums[ind] + helper(ind+2, n, nums, dp);
        int notTake = 0 + helper(ind+1, n, nums, dp);

        return dp[ind] = max(take, notTake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++){
            int take = nums[i] + prev2;
            int notTake = 0 + prev1;
            // dp[i] = max(take, notTake);
            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
        // return max(helper(0, n, nums, dp), helper(1, n, nums, dp));
    }
};