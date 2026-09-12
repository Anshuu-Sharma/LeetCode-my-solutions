class Solution {
public:
    int maxSum = INT_MIN;
    void recursion(int ind, int sum, vector<int>& nums){
        if(ind == nums.size()) return;

        int temp = sum + nums[ind];
        maxSum = max(maxSum, temp);
        if(temp<0) temp = 0;
        recursion(ind+1, temp, nums);
    }
    int tabulation(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n);

        dp[n-1] = nums[n-1]; 
        int maxSum = dp[n-1]; 

        for(int i = n-2; i>=0; i--){
            dp[i] = max(nums[i], dp[i+1] + nums[i]);

            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
    int maxSubArray(vector<int>& nums) {
        recursion(0, 0, nums);
        return tabulation(nums);
    }
};