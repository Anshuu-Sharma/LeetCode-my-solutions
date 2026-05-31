class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int minReachable = n;
        int resultCity = -1;
        
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            
            while (!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                
                if (d > dist[u]) continue;
                
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }
            
            if (count <= minReachable) {
                minReachable = count;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};