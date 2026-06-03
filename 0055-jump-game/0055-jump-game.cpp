class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false;
            }
            maxReach = std::max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;
            }
        }
        return true;
    }
};