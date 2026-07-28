class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currentXor = arr[i];
            for (int k = i + 1; k < n; k++) {
                currentXor ^= arr[k];
                // If XOR sum of subarray arr[i...k] is 0,
                // there are (k - i) valid choices for j.
                if (currentXor == 0) {
                    ans += (k - i);
                }
            }
        }

        return ans;
    }
};