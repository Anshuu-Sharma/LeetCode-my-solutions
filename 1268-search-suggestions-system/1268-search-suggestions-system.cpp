class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        vector<string> suggestions;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];

            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // Ensure lexicographical order

        // Build Trie
        for (string& product : products)
            insert(product);

        vector<vector<string>> result;
        TrieNode* node = root;

        for (char c : searchWord) {
            if (node && node->children[c - 'a'])
                node = node->children[c - 'a'];
            else
                node = nullptr;

            result.push_back(node ? node->suggestions : vector<string>{});
        }

        return result;
    }
};