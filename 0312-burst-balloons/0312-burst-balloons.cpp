class Solution {
public: 
    // int recursionHelper(vector<int>& nums, int i, int j,vector<vector<int>> dp){
    //     if(i>j) return dp[i][j] = 0;
    //     int maxi = INT_MIN;

    //     for(int ind = i; ind<=j; ind++){
    //         int cost = (nums[i-1] * nums[ind] * nums[j+1]) + recursionHelper(nums, i, ind-1,dp) + recursionHelper(nums, ind+1, j, dp);
    //         maxi = max(maxi, cost);
    //     }

    //     return dp[i][j] = maxi;   
    // }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(n,0));
        // return recursionHelper(nums, 1, n-2, dp);

       for(int i = n-2; i>=1; i--){
           for(int j = i; j<=n-2; j++){
            long long maxi = LONG_MIN;
                for(int ind = i; ind<=j; ind++){
            long long cost = (nums[i-1] * nums[ind] * nums[j+1]) + dp[i][ind-1] + dp[ind+1][j];
            maxi = max(maxi, cost);
        }
         dp[i][j] = maxi;
           }
       }
       return dp[1][n-2];
    }
};