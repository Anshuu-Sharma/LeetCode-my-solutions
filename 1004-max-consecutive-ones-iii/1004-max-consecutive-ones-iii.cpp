class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0; 
        int right = 0;
        int numZeroes = 0;
        int ans = 0;
        while(right<n){
            if(nums[right]==0){
                numZeroes++;
            }
            while(numZeroes > k){
                if(nums[left] == 0) numZeroes--;
                left++;
            }
            int len = right - left + 1;
            ans = max(ans, len);
            right++;
        }
        return ans;
    }
};