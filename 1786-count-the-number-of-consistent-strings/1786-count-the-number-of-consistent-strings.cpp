class Solution {
public:

    bool check(string allowed, string words){
        bool ans = true;
        for(int i = 0; i<words.size(); i++){
            if(allowed.find(words[i]) == -1) ans = false;
        }
        return ans;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for(int i = 0; i<words.size(); i++){
            if(check(allowed, words[i])) ans++;
        }

        return ans;
    }
};