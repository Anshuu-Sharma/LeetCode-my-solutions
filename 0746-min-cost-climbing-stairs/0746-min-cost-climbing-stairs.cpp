class Solution {
public:
    int helper(int i, vector<int>& cost, vector<int>& memo) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (memo[i] != -1) return memo[i];
        
        memo[i] = cost[i] + min(helper(i - 1, cost, memo), helper(i - 2, cost, memo));
        return memo[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        return min(helper(n - 1, cost, memo), helper(n - 2, cost, memo));
    }
};