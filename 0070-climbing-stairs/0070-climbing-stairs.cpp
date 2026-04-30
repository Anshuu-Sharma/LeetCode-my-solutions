class Solution {
public:
    // Tabulation dp approach -> bottom-up apporach -> space optimized apporach
    int climbStairs(int n) {
        // vector<int> dp(n+1, 0);
        if(n==1) return 1;

        int prev_1 = 1;
        int prev_2 = 1;
        int curr = 0;
        for(int i = 2; i<=n; i++){
            curr = prev_1 + prev_2;
            prev_1 = prev_2;
            prev_2 = curr;
        }

        return curr;
    }
};