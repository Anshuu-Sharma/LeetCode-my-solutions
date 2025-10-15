class Solution {
public:
    bool isIncreasing(vector<int> nums, int idx, int k) {
        int n = nums.size();
        int prev = nums[idx];
        for(int i = 1; i<k; i++){
            if(idx+i<n && prev < nums[idx+i]) prev = nums[idx+i];
            else return false;
        }
        return true;
    }
    
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(2*k>n) return false;

        for(int i = 0; i<=(n-2*k); i++) {
            if(isIncreasing(nums, i, k)){
                if(isIncreasing(nums, i+k, k)) return true;
            }
        }

        return false;
    }
};