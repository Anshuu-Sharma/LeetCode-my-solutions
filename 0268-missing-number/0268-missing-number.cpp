class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // MTD 1
        // int n = nums.size();
        // int sum = ((n*n) + n) / 2;
        // int actualsum =0;
        // for ( auto it : nums) {
        //     actualsum +=it;
        // }
        // return (sum - actualsum);

        // MTD 2
        int xor1 = 0;
        int xor2 = 0;
         for(int i = 0; i<nums.size(); i++)
        {
            xor1 = xor1^nums[i];
            xor2 = xor2^i;
        }
        xor2 = xor2^nums.size();
        return xor1^xor2; 
    }
};