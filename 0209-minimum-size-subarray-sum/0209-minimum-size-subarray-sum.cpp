class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int l = 0; 
        int sum = 0;
        int ans = INT_MAX;

        for(int r = 0; r<n; r++) {
            sum += nums[r];

            while(r<n && sum>=target){
                ans = min(ans, r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(ans == INT_MAX) ans = 0;
        return ans;
    }
};