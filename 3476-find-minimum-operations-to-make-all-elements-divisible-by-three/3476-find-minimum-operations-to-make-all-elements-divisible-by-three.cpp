class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(auto it : nums)
        {
            if(it%3 != 0)
            {
                if((it-1)%3 == 0) cnt++;
                else if((it+1)%3 == 0) cnt++;
            }
        }
        return cnt;
    }
};