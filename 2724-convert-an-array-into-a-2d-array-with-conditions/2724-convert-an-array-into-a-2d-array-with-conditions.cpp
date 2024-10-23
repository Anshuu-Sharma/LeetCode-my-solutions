class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> hash(nums.size() + 1, 0);
        for(auto it : nums){
            hash[it]++;
        }
        while(*max_element(hash.begin(), hash.end()) > 0){
            vector<int> temp;
            for(int i = 1; i<=nums.size(); i++){
                if(hash[i] > 0){
                    temp.push_back(i);
                    hash[i]--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};