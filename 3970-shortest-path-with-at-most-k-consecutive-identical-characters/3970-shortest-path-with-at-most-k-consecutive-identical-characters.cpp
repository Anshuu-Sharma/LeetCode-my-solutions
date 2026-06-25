class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        // adjacency matrix
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        // Min-Heap Priority Queue: {total_weight, current_node, consecutive_count}
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>
        > pq;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto [currW, u, count] = pq.top();
            pq.pop();

            if(u == n-1){
                return currW;
            }

            if(currW > dist[u][count]){
                continue;
            }

            for(const auto& [v, edgeW] : adj[u]){
                int newCount = (labels[u] == labels[v]) ? count + 1:1;

                if(newCount <= k){
                    int newW = currW + edgeW;

                    if(newW < dist[v][newCount]){
                        dist[v][newCount] = newW;
                        pq.push({newW, v, newCount});
                    }
                }
            }
        }
        return -1;

    }
};