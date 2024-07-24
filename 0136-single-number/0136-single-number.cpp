class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int xor1 = 0;
        for(auto it : nums) {
            xor1 ^= it;
        }
        return xor1;
    }
};