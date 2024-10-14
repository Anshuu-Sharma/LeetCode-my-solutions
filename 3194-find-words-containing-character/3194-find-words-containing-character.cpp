class Solution {
public:

    bool check(string s, char x){
        for(auto it : s){
            if(it == x) return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        if(n == 0) return {};
        vector<int> ans;

        for(int i = 0; i<n; i++){
            if(check(words[i], x)) ans.push_back(i);
        }
        return ans;
    }
};