class TrieNode {
public:
    TrieNode* children[26];
    int count; // Changed from bool isEndofWord to handle duplicate words

    TrieNode() {
        count = 0;
        for(int i = 0; i < 26; i++){
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
        for(char c : word) {
            int index = c - 'a';
            // if char c is not present then add it
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            // move forward
            node = node->children[index];
        }
        // Increment count to mark the end of a word (and handle duplicates)
        node->count++; 
    }
    
    // Adapted from your search/startsWith methods
    int countValidPrefixSuffixes(string word) {
        TrieNode* node = root;
        int totalPairs = 0;
        
        for(char c : word) {
            int index = c - 'a';
            
            // If the path breaks, no more previous words can match
            if(node->children[index] == nullptr) {
                break;
            }
            node = node->children[index];
            
            // Accumulate counts of previously seen words that ended exactly here
            totalPairs += node->count; 
        }
        return totalPairs;
    }
};

class Solution {
private:
    // Helper function to interleave characters from the front and back
    string getInterleaved(const string& s) {
        string res = "";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            res += s[i];           // Prefix character
            res += s[n - 1 - i];   // Suffix character
        }
        return res;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Trie trie;
        int count = 0;
        
        for (const string& word : words) {
            string interleaved = getInterleaved(word);
            
            // 1. Add any valid (i < j) pairs where words[i] is a prefix/suffix
            count += trie.countValidPrefixSuffixes(interleaved);
            
            // 2. Insert the current word into the Trie for future words to check against
            trie.insert(interleaved);
        }
        
        return count;
    }
};