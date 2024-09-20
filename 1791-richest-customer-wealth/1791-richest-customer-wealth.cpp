class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i = 0; i<accounts.size(); i++)
        {
            int sum = 0;
            for(auto it : accounts[i])
            {
                sum+= it;
            }
            if(sum>max) max = sum;
        }
        return max;
    }
};