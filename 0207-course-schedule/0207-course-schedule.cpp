class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n==0) return true;

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

       

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();

            for(auto it:adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == numCourses) return true;
        return false;

    }
};