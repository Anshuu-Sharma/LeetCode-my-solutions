class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(n, 0), maxRight(n, 0);

        // tells us the maxiumum till i from the left
        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }

        // tells us the maximum till i from the right side
        maxRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }

        long long maxi = 0;
        for (int j = 1; j < n - 1; j++) {
            long long leftMax = maxLeft[j - 1];   // Max value before j
            long long rightMax = maxRight[j + 1]; // Max value after j
            maxi = max(maxi, (leftMax - nums[j]) * rightMax);
        }
        
        return maxi;
    }
};
