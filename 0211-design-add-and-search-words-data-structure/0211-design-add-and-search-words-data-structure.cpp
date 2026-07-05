class WordDictionary {
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEndOfWord = false;
        }
    };
    
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        // Use a helper function to allow for recursion when checking '.'
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int start, TrieNode* node) {
        for (int i = start; i < word.length(); i++) {
            char c = word[i];
            
            if (c == '.') {
                // If it's a dot, we must try all possible existing paths
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] != nullptr) {
                        // Recursively check if the rest of the word matches this path
                        if (searchHelper(word, i + 1, node->children[j])) {
                            return true;
                        }
                    }
                }
                // If none of the paths worked, return false
                return false;
            } else {
                // Normal character matching
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    return false;
                }
                node = node->children[index];
            }
        }
        // At the end of the word, check if it's marked as the end of an inserted word
        return node->isEndOfWord;
    }
};