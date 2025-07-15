class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;

        vector<pair<int, string>> temp;
        int i = 0;
        for(auto it:words){
            if(!mpp.count(it)){
                mpp[it] = i++;
                temp.push_back({1, it});
            }
            else temp[mpp[it]].first++;
        }

        sort(temp.begin(),temp.end(), [](auto& a, auto& b){
            if(a.first>b.first) return true;
            else if(a.first == b.first && a.second < b.second) return true;
            return false;
        });

        vector<string> ans;
        for(int i = 0 ; i<k; i++) {
            ans.push_back(temp[i].second);
        }

        return ans;

    }
};