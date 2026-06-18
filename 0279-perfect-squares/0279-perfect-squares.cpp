class Solution {
    vector<vector<int>> memo;
public:
    int helper(int num, int target) {
        if (target == 0) return 0;
        if (num * num > target) return 1e9;
        if (memo[num][target] != -1) return memo[num][target];
        
        int take = 1 + helper(num, target - (num * num));
        int notTake = helper(num + 1, target);
        
        return memo[num][target] = min(take, notTake);
    }

    int numSquares(int n) {
        int limit = sqrt(n) + 1;
        memo.assign(limit + 1, vector<int>(n + 1, -1));
        return helper(1, n);
    }
};