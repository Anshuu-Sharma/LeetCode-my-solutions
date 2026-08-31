class Solution {
public:
    bool isValid(int target, const vector<int>& nums) {
        long long carry = 0;
        
        // Traverse backwards to greedily push values to the left
        for (int i = nums.size() - 1; i >= 0; --i) {
            long long current = nums[i] + carry;
            if (current > target) {
                // Excess value must be moved to nums[i-1]
                carry = current - target;
            } else {
                carry = 0;
            }
        }
        
        // If no excess value overflows past nums[0], 'target' is achievable
        return carry == 0;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, nums)) {
                ans = mid;
                right = mid - 1; // Try finding a smaller possible maximum
            } else {
                left = mid + 1;  // 'mid' is too small, increase limit
            }
        }

        return ans;
    }
};