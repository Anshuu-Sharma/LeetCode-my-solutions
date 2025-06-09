class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; // since we start from 1
        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Move to next sibling
                curr += 1;
                k -= steps;
            } else {
                // Move to first child
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    // Counts how many numbers in [prefix, nextPrefix) are <= n
    long long countSteps(int n, long long prefix, long long nextPrefix) {
        long long steps = 0;
        while (prefix <= n) {
            steps += min((long long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }
};
