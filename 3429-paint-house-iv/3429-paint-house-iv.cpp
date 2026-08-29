class Solution {
    long long memo[100005 / 2][4][4];

    long long solve(int i, int prevLeft, int prevRight, int n, vector<vector<int>>& cost) {
        // Base case: processed all pairs up to the middle
        if (i == n / 2) {
            return 0;
        }

        if (memo[i][prevLeft + 1][prevRight + 1] != -1) {
            return memo[i][prevLeft + 1][prevRight + 1];
        }

        long long minCostSum = LLONG_MAX;

        // Try all 3 colors for house i and house (n - 1 - i)
        for (int c1 = 0; c1 < 3; ++c1) {
            for (int c2 = 0; c2 < 3; ++c2) {
                // Condition 1: Equidistant houses must not have the same color
                if (c1 == c2) continue;

                // Condition 2: Adjacent houses must not have the same color
                if (prevLeft != -1 && c1 == prevLeft) continue;
                if (prevRight != -1 && c2 == prevRight) continue;

                // Calculate cost for painting current pair and recurse
                long long currentCost = cost[i][c1] + cost[n - 1 - i][c2];
                long long nextCost = solve(i + 1, c1, c2, n, cost);

                minCostSum = min(minCostSum, currentCost + nextCost);
            }
        }

        return memo[i][prevLeft + 1][prevRight + 1] = minCostSum;
    }

public:
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(memo, -1, sizeof(memo));
        return solve(0, -1, -1, n, cost);
    }
};