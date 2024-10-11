class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
        vector<int> vis(nums.size()+1, -1);

        int cnt = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == x){
                vis[cnt++] = i;
            }
        }

        for(int i = 0; i<queries.size(); i++)
        {
           if(queries[i] <= nums.size()) ans.push_back(vis[queries[i]]);
           else ans.push_back(-1);
        }     
        return ans;
    }
};