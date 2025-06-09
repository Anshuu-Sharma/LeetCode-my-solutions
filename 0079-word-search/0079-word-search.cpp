#include <vector>
#include <string>
using namespace std;

class Solution {
public: 
    bool dfs(int r, int c, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] || board[r][c] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) return true;
        
        visited[r][c] = true;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (dfs(nr, nc, index + 1, board, word, visited)) {
                visited[r][c] = false;
                return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Pruning Step: Check character frequencies
        vector<int> boardFreq(128, 0); // ASCII characters
        for (auto& row : board) {
            for (char c : row) {
                boardFreq[c]++;
            }
        }
        vector<int> wordFreq(128, 0);
        for (char c : word) {
            wordFreq[c]++;
        }
        for (int i = 0; i < 128; ++i) {
            if (wordFreq[i] > boardFreq[i]) {
                return false; // Prune if any character is insufficient
            }
        }
        
        // Start DFS from cells matching the first character
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
