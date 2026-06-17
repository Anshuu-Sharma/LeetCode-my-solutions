#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day we need to travel
        int lastDay = days.back();
        
        // DP array to store the minimum cost up to each day
        vector<int> dp(lastDay + 1, 0);
        
        // Use an unordered_set for O(1) lookups to check if a day is a travel day
        unordered_set<int> travelDays(days.begin(), days.end());
        
        for (int i = 1; i <= lastDay; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                // If it's not a travel day, the cost is the same as the previous day
                dp[i] = dp[i - 1];
            } else {
                // If it is a travel day, find the minimum cost among the 3 pass options
                int oneDay = dp[i - 1] + costs[0];
                int sevenDay = dp[max(0, i - 7)] + costs[1];
                int thirtyDay = dp[max(0, i - 30)] + costs[2];
                
                dp[i] = min({oneDay, sevenDay, thirtyDay});
            }
        }
        
        // The answer is the minimum cost to cover up to the last travel day
        return dp[lastDay];
    }
};