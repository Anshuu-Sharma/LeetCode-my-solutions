class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        // Handle the edge case where no product can be strictly less than k
        if (k <= 1) return 0;

        int count = 0;
        int left = 0;
        long long currentProduct = 1; // Use long long to avoid overflow

        for (int right = 0; right < nums.size(); ++right) {
            currentProduct *= nums[right];

            // If the product is too large, shrink the window from the left
            while (currentProduct >= k) {
                currentProduct /= nums[left];
                left++;
            }

            // The number of valid subarrays ending at 'right' is the window size
            count += (right - left + 1);
        }

        return count;
    }
};