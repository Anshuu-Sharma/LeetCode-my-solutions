class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int m = heights.size();
        int n = heights[0].size();
        int mini = INT_MAX;

        vector<vector<int>> dist(m, vector<int>(n,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (r == m - 1 && c == n - 1) return diff;
                
                if(nr>=0 && nc>=0 && nr<m && nc<n) {
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }

            
            }
        }
        return -1;
    }
};