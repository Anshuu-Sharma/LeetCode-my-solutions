class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);

        for(int i = 0; i<V; i++){
            for(auto it:graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNode;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }   
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            
            for(auto it:revGraph[node]){
                // indegree[it]--;
                if(--indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};