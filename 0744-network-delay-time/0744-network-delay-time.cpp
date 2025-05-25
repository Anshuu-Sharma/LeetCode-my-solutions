class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,k});
        vector<int> distance(n+1,INT_MAX);   
        distance[k] = 0;

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times) {
            adj[it[0]].push_back({it[1],it[2]});
        }


        while(!q.empty()) {
            auto [dis, node] = q.top();
            q.pop();

            if (dis > distance[node]) continue;

           for (auto& [adjNode, adjWeight] : adj[node]){

                if(adjWeight+dis < distance[adjNode]) {
                    distance[adjNode] = adjWeight + dis;
                    q.push({distance[adjNode], adjNode});
                }
            }
        }
       int maxTime = 0;
        for(int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            maxTime = max(maxTime, distance[i]);
        }
        return maxTime;
    }
};