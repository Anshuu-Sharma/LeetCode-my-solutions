class Solution {
public:
//KNK
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (const string& word : words) {
            count[word]++;
        }
        
        int maxLen = 0;
        bool hasCentral = false;
        
        for (auto& [word, freq] : count) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev) {
                // Palindromic word like "gg"
                maxLen += (freq / 2) * 4;
                if (freq % 2 == 1) hasCentral = true;
            } else if (word < rev && count.count(rev)) {
                // Pair word with its reverse, only process one direction to avoid double counting
                int pairs = min(freq, count[rev]);
                maxLen += pairs * 4;
            }
        }
        if (hasCentral) maxLen += 2;
        return maxLen;

    }
};