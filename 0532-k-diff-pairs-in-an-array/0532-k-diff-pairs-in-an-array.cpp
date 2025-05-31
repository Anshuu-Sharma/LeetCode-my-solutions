class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> uniquePairs;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    int a = min(nums[i], nums[j]);
                    int b = max(nums[i], nums[j]);
                    uniquePairs.insert({a, b});
                }
            }
        }
        return uniquePairs.size();
    }
};
