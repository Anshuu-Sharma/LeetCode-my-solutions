#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Binary search for the smallest distance
        int low = 0;
        int high = nums[n - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Count pairs with distance <= mid
            int count = 0;
            int left = 0;
            for (int right = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid) {
                    left++;
                }
                count += (right - left);
            }
            
            // Decision logic
            if (count >= k) {
                high = mid; // Try smaller distances
            } else {
                low = mid + 1; // Need larger distance
            }
        }
        
        return low;
    }
};