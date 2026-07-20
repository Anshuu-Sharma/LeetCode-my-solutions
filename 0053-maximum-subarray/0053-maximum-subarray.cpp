class Solution {
public:
    // sliding window
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), r = 0;
        int sum = 0;
        int ans = INT_MIN;
        while(r<n){
            if(sum<0){
                sum = 0;
            }
            sum += nums[r++];
            ans = max(ans, sum);
        }
        return ans;
    }
};