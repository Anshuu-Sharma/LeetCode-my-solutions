class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        
        // this i helps in remembering the occurance of a string bcz in vec when u inc the cnt u have to know the number so assigning it a number(first occurance index) is helpful
        int i = 0;
        vector<pair<int, string>> temp;

        for(auto it:words) {
            if(!mpp.count(it)){
                mpp[it] = i++;
                temp.push_back({1, it});
            }
            temp[mpp[it]].first++;
        }

        sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
           if(a.first > b.first) return true;
           else if(a.first == b.first && a.second < b.second) return true;
           return false;
        });

        vector<string> ans(k);
        for(int i=0;i<k;i++)ans[i]=temp[i].second;
        return ans;
    }
};