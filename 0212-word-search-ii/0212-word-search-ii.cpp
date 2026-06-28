class TrieNode {
public:
    string word = "";
    TrieNode* children[26];
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Solution {
private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int i = c - 'a';
                if (curr->children[i] == nullptr) {
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
            }
            curr->word = word; // Store the word at the leaf node
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& result) {
        char c = board[i][j];
        
        // Return if out of bounds, already visited ('#'), or no matching prefix in Trie
        if (c == '#' || p->children[c - 'a'] == nullptr) return;

        p = p->children[c - 'a'];
        
        // If we reach a node with a stored word, we found a match!
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = ""; // Clear the word to prevent duplicate entries in the result
        }

        // Mark current cell as visited
        board[i][j] = '#';
        
        // Explore all 4 adjacent directions
        if (i > 0) dfs(board, i - 1, j, p, result); // Up
        if (j > 0) dfs(board, i, j - 1, p, result); // Left
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result); // Down
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result); // Right
        
        // Backtrack: restore the original character
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};