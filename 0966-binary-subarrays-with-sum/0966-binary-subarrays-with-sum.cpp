class Solution {
public:
    
    int f(vector<int>& nums, int goal) {
        int l = 0 , r = 0, cnt = 0;
        long long sum1 = 0; 
        while(r<nums.size()) {
            sum1 += nums[r];
            while(sum1 > goal  && l <= r) {
                sum1 -= nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);
    }
};