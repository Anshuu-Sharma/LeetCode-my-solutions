class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int>ans;
        for(int i=0;i<values.size();i++)
        {
            for(int j=0;j<values[0].size();j++)
            {
                ans.push_back(values[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        long long i=1;
        long long res=0;
        for(long long j=0;j<ans.size();j++)
        {
            res=res+(ans[j]*i);
            i++;
        }
        return res;
    }
};