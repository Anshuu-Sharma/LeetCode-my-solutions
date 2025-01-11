class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();       
        if(m==1 && grid[0][0] == 0) return 1; 
        if(grid[0][0] == 1 || grid[m-1][n-1]) return -1;
        queue<pair<int,pair<int, int>>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;   
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    int nr = r + i;
                int nc = c + j;
                if(nr>=0 && nc >=0 && nr<m && nc<n && grid[nr][nc]==0 && (distance + 1 < dist[nr][nc])){
                    dist[nr][nc]=distance+1;
                    if(nr==m-1 && nc == n-1){
                        return distance+1;
                    }
                    q.push({distance+1,{nr, nc}});
                    }
                }
                
            }
        }
        return -1;
    }
};