class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[r][c] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && board[nr][nc] == 'X'){
                dfs(nr, nc, m, n, visited, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int cnt = 0;
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'X'){
                    cnt++;
                    dfs(i, j, m, n, visited, board);
                }
            }
        }

        return cnt;
    }
};