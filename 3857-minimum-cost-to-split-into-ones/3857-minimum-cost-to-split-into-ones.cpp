class Solution {
public:
    int helper(int n, vector<int>& memo){
        if(n == 1) return 0; // Fixed base case
        if(memo[n] != -1) return memo[n]; // Return cached result
        
        int cost = INT_MAX;
        for(int i = 1; i <= n / 2; i++){
            cost = min(cost, (i * (n - i)) + helper(i, memo) + helper(n - i, memo));
        }
        return memo[n] = cost; // Cache and return
    }
    
    int minCost(int n) {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }
};