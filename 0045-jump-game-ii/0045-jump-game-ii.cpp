class Solution {
public:
    int recursion(int ind, int n, vector<int>& nums){
        if(ind >= n-1) return 0;

        int jump = 1e9;
        for(int i = 1; i<=nums[ind]; i++){
            jump = min(jump, 1 + recursion(ind+i, n, nums));
        }
        
        return jump;
    }
    int tabulation(vector<int>& nums){
        int n = nums.size();

        vector<int> dp(n,1e9);
        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            for(int j = 1; j<=nums[i]; j++){
                if(i+j<n) dp[i] = min(dp[i], 1 + dp[i+j]);
            }
        }

        return dp[0];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        // return recursion(0,n,nums);
        return tabulation(nums);
    }
};