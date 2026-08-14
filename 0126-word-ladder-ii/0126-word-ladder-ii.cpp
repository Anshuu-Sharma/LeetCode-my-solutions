class Solution {
    unordered_map<string, int> mpp; // Stores the shortest distance to each word
    vector<vector<string>> ans;
    string bWord;

private:
    void dfs(string word, vector<string>& seq) {
        // Base Case: We've backtracked all the way to the start
        if (word == bWord) {
            vector<string> temp = seq;
            reverse(temp.begin(), temp.end()); // Reverse because we started from endWord
            ans.push_back(temp);
            return;
        }
        
        int steps = mpp[word];
        int sz = word.size();
        
        // Generate all possible previous words
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // If the word exists in our map AND is exactly one level above us
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original; // Backtrack character
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        bWord = beginWord;
        
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        
        int sz = beginWord.size();
        
        // Phase 1: BFS to populate the distance map
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            
            // If we've reached the target level, we can stop the BFS early
            if (word == endWord) break; 
            
            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);       // Erase to prevent revisiting
                        mpp[word] = steps + 1; // Record shortest distance
                    }
                }
                word[i] = original;
            }
        }
        
        // Phase 2: DFS to build paths, starting backwards from endWord
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};