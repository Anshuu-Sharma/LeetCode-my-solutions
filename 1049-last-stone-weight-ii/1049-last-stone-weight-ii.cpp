#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int total_sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = total_sum / 2;
        
        // dp[j] will be true if we can form a subset with a sum exactly equal to j.
        std::vector<bool> dp(target + 1, false);
        
        // A sum of 0 is always possible (by picking no stones)
        dp[0] = true; 
        
        for (int stone : stones) {
            // We iterate backwards from 'target' down to 'stone'.
            // Iterating backwards ensures we don't use the same stone more than once.
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }
        
        // Find the largest possible subset sum we were able to form that is <= target
        int max_subset_sum = 0;
        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                max_subset_sum = j;
                break;
            }
        }
        
        // Return the minimum possible difference
        return total_sum - 2 * max_subset_sum;
    }
};