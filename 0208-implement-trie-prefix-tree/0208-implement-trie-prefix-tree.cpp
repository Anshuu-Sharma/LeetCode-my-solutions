class TrieNode{
    public:
    TrieNode* children[26];
    bool isEndofWord;

    TrieNode(){
        isEndofWord = false;
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c:word){
            int index = c - 'a';
            // if char c is not present then add it
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }

            // if char c is present then that prefix already exists
            node = node->children[index];
        }
        node->isEndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c:word){
            int index = c - 'a';

            // if that char is not present then it means that word is not present
            if(node->children[index] == nullptr){
                return false;
            }
            // if that char is present then move forward and check rest chars
            node = node->children[index];
        }
        return node->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            int index = c - 'a';
            if(node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */