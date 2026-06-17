class Solution {
    int dp[2001][2001];
    unordered_map<int, int> stoneMap;

    bool helper(int index, int prevJump, const vector<int>& stones) {
        // Base case: Reached the last stone
        if (index == stones.size() - 1) {
            return true;
        }

        // Return memoized result if already computed
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump];
        }

        bool canReachEnd = false;
        
        // Explore all 3 possible next jump distances
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0) {
                int nextPosition = stones[index] + nextJump;
                
                // If the next position is a valid stone, jump to it
                if (stoneMap.count(nextPosition)) {
                    canReachEnd = canReachEnd || helper(stoneMap[nextPosition], nextJump, stones);
                }
            }
        }

        return dp[index][prevJump] = canReachEnd;
    }

public:
    bool canCross(vector<int>& stones) {
        // The first jump must always be exactly 1 unit
        if (stones[1] != 1) return false;

        // Map each stone's position to its index for O(1) lookups
        for (int i = 0; i < stones.size(); i++) {
            stoneMap[stones[i]] = i;
        }

        // Initialize memoization table with -1
        memset(dp, -1, sizeof(dp));

        // Start from index 1 (the second stone), with a previous jump of 1
        return helper(1, 1, stones);
    }
};