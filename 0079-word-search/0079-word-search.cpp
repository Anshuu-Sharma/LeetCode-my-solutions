class Solution {
public: 
    bool dfs(int r, int c, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
         if (index == word.size()-1) return true; 
         visited[r][c] = true;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i = 0; i<4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && !visited[nr][nc] && word[index+1] == board[nr][nc] && dfs(nr, nc, index + 1, board, word, visited)) {
                return true;
            }
        }
        visited[r][c] = false; 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};