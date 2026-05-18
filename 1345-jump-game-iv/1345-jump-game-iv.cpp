class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;

        // making ranges for type 3 jump
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int node = q.front();
                q.pop();

                if(node == n - 1) return steps;

                // left
                if(node - 1 >= 0 && !visited[node - 1]) {
                    visited[node - 1] = 1;
                    q.push(node - 1);
                }

                // right
                if(node + 1 < n && !visited[node + 1]) {
                    visited[node + 1] = 1;
                    q.push(node + 1);
                }

                // same value jumps
                for(int next : mpp[arr[node]]) {

                    if(!visited[next]) {
                        visited[next] = 1;
                        q.push(next);
                    }
                }

                // VERY IMPORTANT OPTIMIZATION
                mpp[arr[node]].clear();
            }

            steps++;
        }

        return -1;
    }
};