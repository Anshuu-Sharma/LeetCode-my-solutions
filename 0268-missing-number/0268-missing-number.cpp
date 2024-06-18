class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
cin.tie(NULL);
        int n = nums.size();
        int sum = ((n*n) + n) / 2;
        int actualsum =0;
        for ( auto it : nums) {
            actualsum +=it;
        }

        return (sum - actualsum);
    }
};