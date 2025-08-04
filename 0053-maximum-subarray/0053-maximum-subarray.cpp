class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum  = INT_MIN;
        int n = nums.size();
        int l = 0;
        int r = 0;

        int sum = 0;
        while(r<n){
            if(sum<0){
                while(sum!=0){
                    sum-=nums[l++];
                }
            }
            sum += nums[r];
            maxSum = max(maxSum, sum);
            r++;
        }
        return maxSum;
    }
};