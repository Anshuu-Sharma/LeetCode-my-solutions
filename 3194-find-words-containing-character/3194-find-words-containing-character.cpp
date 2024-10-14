class Solution {
public:

    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        if (n == 0) return {};

        vector<int> ans;
        string pattern = string(1, x);  // Create a pattern for the character x
        regex r(pattern);  // Regex to search for character x

        for (int i = 0; i < n; i++) {
            if (regex_search(words[i], r)) {
                ans.push_back(i);  // If the character x is found, add the index
            }
        }
        return ans;
    }
};