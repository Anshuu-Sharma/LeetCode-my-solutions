class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        // {{1, 100}, ...}

        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }


        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q; // {stops, {node, dist}}
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int node = it.second.first;
            int stops = it.first;
            int distance = it.second.second;


            for(auto it:adj[node]){
                int newNode = it.first;
                int newWeight = it.second;

                if(distance + newWeight < dist[newNode] && stops<=k){
                    dist[newNode] = distance + newWeight;
                    q.push({stops+1,{newNode, dist[newNode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};