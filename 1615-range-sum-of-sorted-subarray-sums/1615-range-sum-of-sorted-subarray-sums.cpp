class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> temp;

        for(int i = 0; i<n; i++) {
            long long cnt = 0;
            for(int j = i; j<n; j++) {
                cnt += nums[j];
                temp.push_back(cnt);
            }

        }

        ranges::sort(temp);

        long long sum = 0; 
        int MOD = 1e9 + 7;
        for(int i = left-1; i<=right-1; i++) {
            sum = (sum + temp[i]) % MOD;
        }

        return sum;
    }
};