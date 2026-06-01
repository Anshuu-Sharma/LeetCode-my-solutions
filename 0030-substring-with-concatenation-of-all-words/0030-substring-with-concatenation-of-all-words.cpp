class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.length();

        // If the string is shorter than the required concatenation, return early
        if (n < totalLen) return result;

        // Populate the frequency map for the required words
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Loop over the word length to cover all possible starting offsets (0 to wordLen - 1)
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            int count = 0; // Tracks the number of valid words currently matched in the window
            unordered_map<string, int> seenWords;

            while (right + wordLen <= n) {
                // Extract the next word of size wordLen and slide the right pointer
                string word = s.substr(right, wordLen);
                right += wordLen;

                // Check if the extracted word is one of our required words
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;

                    // If we have more occurrences of this word than needed, 
                    // shrink the window from the left until it becomes valid again
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If our window contains exactly the right number of valid words, we found a match!
                    if (count == numWords) {
                        result.push_back(left);
                        
                        // Slide the window forward by one word to keep looking for more matches
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    // The extracted word is NOT in our required list.
                    // This breaks any valid sequence, so we reset our trackers and jump the left pointer.
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};