#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times)
            adj[edge[0]].emplace_back(edge[1], edge[2]);

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        vector<bool> visited(n + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (visited[node]) continue;
            visited[node] = true;

            for (auto& [adjNode, adjWeight] : adj[node]) {
                if (!visited[adjNode] && dis + adjWeight < distance[adjNode]) {
                    distance[adjNode] = dis + adjWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            maxTime = max(maxTime, distance[i]);
        }
        return maxTime;
    }
};
