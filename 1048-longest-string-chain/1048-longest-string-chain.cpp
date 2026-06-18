class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // 1. Sort the words by their lengths in ascending order
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp;
        int longestChain = 1;
        
        // 2. Iterate through the sorted words to build up the DP table
        for (const string& word : words) {
            dp[word] = 1; // Every word is at least a chain of 1
            
            // 3. Try removing each character to find valid predecessors
            for (int i = 0; i < word.length(); ++i) {
                string prevWord = word.substr(0, i) + word.substr(i + 1);
                
                // 4. If the predecessor is in our map, update the current word's chain
                if (dp.count(prevWord)) {
                    dp[word] = max(dp[word], dp[prevWord] + 1);
                }
            }
            
            // 5. Keep track of the global maximum chain length found
            longestChain = max(longestChain, dp[word]);
        }
        
        return longestChain;
    }
};