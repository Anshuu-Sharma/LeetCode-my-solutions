#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width ascending. If widths are equal, sort by height descending.
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Descending height for same width
            }
            return a[0] < b[0];     // Ascending width
        });
        
        // Step 2: Extract heights and find LIS using binary search (O(N log N))
        vector<int> lis;
        
        for (const auto& env : envelopes) {
            int height = env[1];
            
            // Find the first element in lis that is >= the current height
            auto it = lower_bound(lis.begin(), lis.end(), height);
            
            if (it == lis.end()) {
                // If no such element is found, this height extends our LIS
                lis.push_back(height);
            } else {
                // Otherwise, overwrite the existing element to keep the values in lis as small as possible
                *it = height;
            }
        }
        
        return lis.size();
    }
};