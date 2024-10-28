class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        // Sort the input for easier processing
        std::sort(nums.begin(), nums.end());

        // Use a set to keep track of available numbers
        std::unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxLength = -1;

        for (int num : nums) {
            int currentLength = 0;
            long long current = num;

            // Check if the next number in the streak exists
            while (numSet.find(current) != numSet.end()) {
                currentLength++;

                // Check if the next square would overflow
                if (current > std::numeric_limits<long long>::max() / current) {
                    break; // Break the loop to prevent overflow
                }

                current *= current; // Move to the next square
            }

            maxLength = std::max(maxLength, currentLength);
        }

        return maxLength == 1 ? -1 : maxLength;
    }
};
