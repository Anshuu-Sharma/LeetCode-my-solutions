class Solution {
public:
    int dfs(int i , int j , int sum , vector<int>& stones ,
            vector<vector<int>>& dp){
        if(i >= j){
            return 0;
        }
        if(sum < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int choose_front = sum - stones[i] - 
                    dfs(i + 1 , j , sum - stones[i] , stones , dp);
        int choose_back = sum - stones[j] - 
                    dfs(i , j - 1 , sum - stones[j] , stones , dp);
        int profit = max(choose_back , choose_front);
        return dp[i][j] = profit;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
        int sum = 0 ;
        for(auto it : stones){
            sum += it;
        }
        return dfs(0 , n - 1 , sum , stones , dp);
    }
};