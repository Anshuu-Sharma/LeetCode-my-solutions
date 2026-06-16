class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        // 1. Find the maximum element to know the size of our points array
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // 2. Create an array to store the total points each number can contribute
        // For example, if nums has three 2s, points[2] = 6.
        vector<int> points(max_val + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }

        // 3. Standard House Robber DP approach
        // dp[i] represents the maximum points you can earn considering numbers up to i
        vector<int> dp(max_val + 1, 0);
        
        dp[0] = points[0]; // Always 0, as there is no number 0 in the constraints
        
        if (max_val >= 1) {
            dp[1] = max(points[0], points[1]);
        }

        // Build the DP table
        for (int i = 2; i <= max_val; i++) {
            // Decision: 
            // - Don't take 'i': Score remains whatever we had at 'i-1'
            // - Take 'i': We get points[i], but we MUST add the best score from 'i-2' 
            //   (because taking 'i' forces us to delete 'i-1')
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }

        return dp[max_val];
    }
};