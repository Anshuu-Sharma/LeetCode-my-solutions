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
        int n = nums.size();
        vector<int> memo(nums.size(), 1e9);

        memo[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            for(int j = 1; j <= nums[i]; j++){
                if(i+j < n) memo[i] = min(memo[i], 1 + memo[i+j]);
            }
        }   

        return memo[0];
    }
};