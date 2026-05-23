class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxilen  = 0;
        int l = 0,r = 0, zeroes = 0;
        while(r<n){
            if(nums[r] == 0) zeroes++;
            while(zeroes>k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes<=k) {
                int len = r-l+1;
            maxilen = max(len, maxilen);
            }
            r++;
        }
        return maxilen;
    }
};