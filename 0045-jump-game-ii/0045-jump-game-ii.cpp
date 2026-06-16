class Solution {
public:
    int helper(int ind, vector<int>& nums, vector<int>& memo){
        if(ind >= nums.size() - 1) return 0; // Reached the end
        if(memo[ind] != -1) return memo[ind]; // Return cached result
        
        int ans = 1e9;
        
        // Jump forward based on the CURRENT index's capacity
        for(int i = 1; i <= nums[ind]; i++){
            ans = min(ans, 1 + helper(ind + i, nums, memo));
        }
        
        return memo[ind] = ans; // Save to cache
    }
    
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(0, nums, memo);
    }
};