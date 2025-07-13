class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            for(int i = 0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
            
            if(nrow >= 0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                cntFresh--;
                }
            }
        }

        return (cntFresh == 0) ? tm : -1;
    }
};