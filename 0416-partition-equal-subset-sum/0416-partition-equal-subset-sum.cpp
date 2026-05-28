class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
         for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2) return false;
        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // base conditions
        for(int i = 0; i<n; i++){
            dp[i][0] = 1;
        }

        if(nums[0] <= target) dp[0][nums[0]] = 1;
        
        // Main loop
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
    }
};