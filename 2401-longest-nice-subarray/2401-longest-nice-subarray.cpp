class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 0;
        int used = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Shrink window until there are no overlapping set bits with nums[right]
            while ((used & nums[right]) != 0) {
                used ^= nums[left];
                left++;
            }

            // Include current element in the bitmask
            used |= nums[right];

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};