class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        deque<int> maxDeque; // Keeps track of maximums
        deque<int> minDeque; // Keeps track of minimums
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Maintain the monotonically decreasing maxDeque
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);
            
            // Maintain the monotonically increasing minDeque
            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);
            
            // If the current window violates the limit condition, shrink it from the left
            while (!maxDeque.empty() && !minDeque.empty() && 
                   maxDeque.front() - minDeque.front() > limit) {
                
                // If the element falling out of the window is the current max or min, remove it
                if (maxDeque.front() == nums[left]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[left]) {
                    minDeque.pop_front();
                }
                left++;
            }
            
            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};