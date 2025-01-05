class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        queue<int> q;
        vector<int> indegree(V, 0);
        int cnt = 0;
        vector<vector<int>> adj(V);

        for(auto it:prerequisites){
           indegree[it[1]]++;
           adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return cnt==V;
    }
};