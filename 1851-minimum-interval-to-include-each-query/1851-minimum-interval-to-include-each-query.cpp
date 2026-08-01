#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Store queries with original indices: {query_value, original_index}
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap stores pairs: {interval_size, right_endpoint}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> ans(queries.size());
        int i = 0;
        int n = intervals.size();

        for (auto& [q, idx] : sortedQueries) {
            // 1. Add all intervals that start <= current query
            while (i < n && intervals[i][0] <= q) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }

            // 2. Remove intervals from top that end before current query
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            // 3. Get smallest interval for current query
            ans[idx] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        return ans;
    }
};