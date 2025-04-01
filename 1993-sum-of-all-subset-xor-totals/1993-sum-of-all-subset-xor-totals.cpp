class Solution {
public:
    void helper(vector<int>& nums, int index, int currentXOR, int& sum) {
        if (index == nums.size()) {
            sum += currentXOR;
            return;
        }
        
        // Include nums[index] in the subset
        helper(nums, index + 1, currentXOR ^ nums[index], sum);
        
        // Exclude nums[index] from the subset
        helper(nums, index + 1, currentXOR, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        helper(nums, 0, 0, sum);
        return sum;
    }
};
