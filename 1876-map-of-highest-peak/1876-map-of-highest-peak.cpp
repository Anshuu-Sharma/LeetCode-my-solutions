class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(isWater[i][j] == 1) q.push({{i,j},0}), vis[i][j] = 1;
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            dist[r][c] = step;
            q.pop();

            for(int i = 0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol},step+1});
                }
            }
        }
        return dist;
    }
};