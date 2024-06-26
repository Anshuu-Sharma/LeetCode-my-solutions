class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int xor1 = 0;
        for(int i = 0; i<nums.size(); i++) {
            xor1 = xor1^nums[i];
        }
        return xor1;
    }
};