class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = nums[0];
        int min_so_far = nums[n - 1];
        
        int right = -1;
        int left = -1;

        // Traverse left to right to find the right boundary
        for (int i = 0; i < n; ++i) {
            if (nums[i] < max_so_far) {
                right = i;
            } else {
                max_so_far = nums[i];
            }
        }

        // Traverse right to left to find the left boundary
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > min_so_far) {
                left = i;
            } else {
                min_so_far = nums[i];
            }
        }

        return (right == -1) ? 0 : right - left + 1;
    }
};