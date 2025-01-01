class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> ans(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        // adding intital 0s in queue
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        //
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[r][c] = dist;
            for(int i = 0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc}, dist + 1});
                }
            
            } 
        }

        return ans;

    }
};