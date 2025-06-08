class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int expected = 1;
        for(int i = 0; i<nums.size(); i++){
           if((i > 0 && nums[i] == nums[i-1]) ||  nums[i]<=0) continue;
           else if(nums[i] > 0 && nums[i] != expected) return expected;
           else if(nums[i] > 0 && nums[i] == expected) expected++;
        }
        return expected;
    }
};