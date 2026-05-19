class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1) return 0;

        vector<vector<vector<int>>> vis(
            m,
            vector<vector<int>>(n, vector<int>(k + 1, 0))
        );

        queue<pair<pair<int,int>, pair<int,int>>> q;

        // {{row,col}, {remaining_k, steps}}
        q.push({{0,0}, {k,0}});

        vis[0][0][k] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;

            int rem = curr.second.first;
            int steps = curr.second.second;

            for(int i = 0; i < 4; i++) {

                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    // reached destination
                    if(nr == m-1 && nc == n-1) {
                        return steps + 1;
                    }

                    // empty cell
                    if(grid[nr][nc] == 0 &&
                       !vis[nr][nc][rem]) {

                        vis[nr][nc][rem] = 1;

                        q.push({{nr,nc}, {rem, steps + 1}});
                    }

                    // obstacle
                    else if(grid[nr][nc] == 1 &&
                            rem > 0 &&
                            !vis[nr][nc][rem - 1]) {

                        vis[nr][nc][rem - 1] = 1;

                        q.push({{nr,nc}, {rem - 1, steps + 1}});
                    }
                }
            }
        }

        return -1;
    }
};