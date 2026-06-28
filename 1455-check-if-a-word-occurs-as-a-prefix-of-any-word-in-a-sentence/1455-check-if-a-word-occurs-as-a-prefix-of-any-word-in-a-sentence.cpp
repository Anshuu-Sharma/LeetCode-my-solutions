#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int minIndex;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        minIndex = -1; // -1 denotes that no word has traversed this node yet
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie along with its 1-based index
    void insert(const string& word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            int charIdx = c - 'a';
            if (!node->children[charIdx]) {
                node->children[charIdx] = new TrieNode();
            }
            node = node->children[charIdx];
            
            // Only update minIndex if it's the first time visiting this node
            // This guarantees we always return the minimum index
            if (node->minIndex == -1) {
                node->minIndex = index;
            }
        }
    }
    
    // Search for a prefix and return the minimum index
    int searchPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int charIdx = c - 'a';
            if (!node->children[charIdx]) {
                return -1; // The prefix doesn't exist in the Trie
            }
            node = node->children[charIdx];
        }
        return node->minIndex;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie trie;
        int wordIndex = 1;
        string currentWord = "";
        
        // Parse the sentence and insert each word into the Trie
        for (char c : sentence) {
            if (c == ' ') {
                if (!currentWord.empty()) {
                    trie.insert(currentWord, wordIndex);
                    wordIndex++;
                    currentWord = ""; // Reset for the next word
                }
            } else {
                currentWord += c;
            }
        }
        
        // Insert the final word after the loop finishes
        if (!currentWord.empty()) {
            trie.insert(currentWord, wordIndex);
        }
        
        // Find if the searchWord exists as a prefix
        return trie.searchPrefix(searchWord);
    }
};