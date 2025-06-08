class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;

        sort(words.begin(), words.end());

        vector<pair<int, string>> temp;
        int i = 0;
        while(i<words.size()) {
            int cnt = 0;
            while((i+1) < words.size() && words[i] == words[i+1]) {
                cnt--;
                i++;
            }
            temp.push_back({cnt, words[i]});
            i++;
        }

        sort(temp.begin(), temp.end());
        for(int i = 0; i<k; i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};