class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlen = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(i > maxlen) return false;
            maxlen = max(maxlen, i + nums[i]);
            if(maxlen >= nums.size()-1) return true;
        }
        return true;
    }
};