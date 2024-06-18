class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = ((n*n) + n) / 2;
        int actualsum =0;
        for(auto it : nums) {
            actualsum +=it;
        }

        return (sum - actualsum);
    }
};