class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Unordered map to store the number of 1s for each string index
        unordered_map<int, int> onesCount;
        for (int i = 0; i < strs.size(); i++) {
            int ones = 0;
            for (char c : strs[i]) {
                if (c == '1') {
                    ones++;
                }
            }
            onesCount[i] = ones;
        }
        
        // Initialize a 3D memoization table with -1
        // Dimensions: [index][m + 1][n + 1]
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        return solve(strs, 0, m, n, onesCount, memo);
    }

private:
    int solve(const vector<string>& strs, int index, int m, int n, unordered_map<int, int>& onesCount, vector<vector<vector<int>>>& memo) {
        // Base case: if we've checked all strings
        if (index == strs.size()) {
            return 0;
        }

        // Check the cache: if this state has already been computed, return the stored value
        if (memo[index][m][n] != -1) {
            return memo[index][m][n];
        }

        // Retrieve counts using the map and string length
        int ones = onesCount[index];
        int zeros = strs[index].length() - ones;

        // Option 1: Skip the current string
        int skip = solve(strs, index + 1, m, n, onesCount, memo);

        // Option 2: Include the current string (only if we have enough m and n capacity)
        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + solve(strs, index + 1, m - zeros, n - ones, onesCount, memo);
        }

        // Store the result in the memoization table before returning
        return memo[index][m][n] = max(skip, take);
    }
};