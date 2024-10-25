class Solution {
public:
    int helper(string s){
        int cnt = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' ') cnt++;
        }
        return cnt + 1;
    }
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(int i = 0; i<sentences.size(); i++){
            int cnt_words = helper(sentences[i]);
            maxi = max(maxi, cnt_words);
        }

        return maxi;
    }
};