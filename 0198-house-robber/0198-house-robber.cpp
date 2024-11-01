class Solution {
public: 

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        dp[0] = nums[0];

        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i>1){
                take += dp[i-2];
            } 
    
            int not_take = 0 + dp[i-1];

            dp[i] = max(take, not_take);
        }
        return dp[n-1];
    }

    // MEMOIZATION METHOD
    // int helper(vector<int>& nums, int ind, vector<int>& dp){
    //     if(ind == 0) return dp[ind] = nums[ind];
    //     if(ind < 0) return 0;

    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = nums[ind] + helper(nums, ind-2, dp);
    //     int not_pick = 0 + helper(nums, ind - 1, dp);

    //     return dp[ind] = max(pick, not_pick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n+1, -1);

    //     return helper(nums, n-1, dp);
    // }

    // RECURSION METHOD
    // int helper(vector<int>& nums, int ind){
    //     if(ind == 0) return nums[ind];
    //     if(ind < 0) return 0;

    //     int pick = nums[ind] + helper(nums, ind-2);
    //     int not_pick = 0 + helper(nums, ind - 1);

    //     return max(pick, not_pick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     return helper(nums, n-1);
    // }
};