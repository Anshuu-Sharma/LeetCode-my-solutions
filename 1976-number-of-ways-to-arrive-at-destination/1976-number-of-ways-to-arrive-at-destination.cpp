class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> ways(n, 0);
        vector<long long> dist(n, 1e12);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        long long mode = (1e9 + 7);
        while(!pq.empty()){
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                long long adjNode = it.first;
                long long edW = it.second;

                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mode;
                }
            }
        }
        return ways[n-1] % mode;


    }
};