class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<=n-3; i++)
        {
            for(int j = i+1; j<=n-2; j++)
            {
                for(int k = j+1; k<=n-1; k++){
                    if((nums[j] - nums[i] == diff) && (nums[k] - nums[j]) == diff) cnt++;
                }
            }
        }
        return cnt;
    }
};