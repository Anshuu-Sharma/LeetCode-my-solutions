class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long MOD = 1e9 + 7;
        vector<long long> count(101, 0);
        for (int x : arr) {
            count[x]++;
        }

        long long ans = 0;

        // Iterate over all possible unique values i, j, k from 0 to 100
        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                int k = target - i - j;
                if (k < j || k > 100) continue;
                if (count[i] == 0 || count[j] == 0 || count[k] == 0) continue;

                if (i == j && j == k) {
                    // All three numbers are identical: nC3 = n * (n - 1) * (n - 2) / 6
                    ans += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                } else if (i == j && j != k) {
                    // Two numbers are identical: nC2 * count[k] = (n * (n - 1) / 2) * count[k]
                    ans += (count[i] * (count[i] - 1) / 2) * count[k];
                } else if (i != j && j == k) {
                    // Two numbers are identical: count[i] * nC2
                    ans += count[i] * (count[j] * (count[j] - 1) / 2);
                } else {
                    // All three numbers are distinct
                    ans += count[i] * count[j] * count[k];
                }

                ans %= MOD;
            }
        }

        return ans;
    }
};