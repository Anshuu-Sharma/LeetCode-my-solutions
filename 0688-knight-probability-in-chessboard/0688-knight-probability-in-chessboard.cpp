class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // 8 possible moves for a chess knight
        vector<pair<int, int>> moves = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };

        // dp[r][c] stores the probability of being at (r, c)
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;

        for (int step = 0; step < k; ++step) {
            vector<vector<double>> next_dp(n, vector<double>(n, 0.0));
            
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] > 0) {
                        for (auto& move : moves) {
                            int nr = r + move.first;
                            int nc = c + move.second;
                            
                            // Check if the move remains on the board
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                next_dp[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = move(next_dp);
        }

        // Sum up probabilities for all cells remaining on the board
        double totalProbability = 0.0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                totalProbability += dp[r][c];
            }
        }

        return totalProbability;
    }
};