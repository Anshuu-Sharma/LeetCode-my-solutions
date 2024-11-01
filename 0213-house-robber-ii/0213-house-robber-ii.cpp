class Solution {
public:

    int dp_helper(vector<int> nums){
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1, 0);
        int leave_first_ans = 0;
        int leave_last_ans = 0;
        
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(dp_helper(nums1), dp_helper(nums2));

    }

       
};