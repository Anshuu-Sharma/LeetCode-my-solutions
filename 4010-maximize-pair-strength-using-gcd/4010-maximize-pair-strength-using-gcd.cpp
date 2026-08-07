class Solution {
public:
    long long gcdRecursive(long long a, long long b) {
        return b == 0 ? a : gcdRecursive(b, a % b);
    }

    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                long long g = gcdRecursive(nums[i], nums[j]);
                long long strength = (1LL * nums[i] * nums[j]) / (g * g);
                ans = max(ans, strength);
            }
        }

        return ans;
    }
};