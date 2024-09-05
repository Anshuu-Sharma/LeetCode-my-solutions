class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int cnt = 0;

        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                if(nums[i] == nums[j] && i < j) cnt++;
            }
        }
    return cnt;
    }
};