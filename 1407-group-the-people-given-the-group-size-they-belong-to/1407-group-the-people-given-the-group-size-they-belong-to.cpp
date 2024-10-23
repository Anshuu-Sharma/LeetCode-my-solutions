class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;

        vector<pair<int , int>> storage;
        //.    pair<size, index>
        for(int i = 0; i<groupSizes.size(); i++){
            storage.push_back({groupSizes[i], i});
        }
        sort(storage.begin(), storage.end());
        int j = 0;
        while(j<storage.size()){
            int loop = storage[j].first;
            vector<int> temp; 
            for(int i = 0; i<loop; i++){
                temp.push_back(storage[j].second);
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};