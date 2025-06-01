class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        vector<vector<long long>> dp(limit+1, vector<long long>(limit+1,-1));
        

        for(long long i = 0; i<=limit; i++) {
            for(long long j = 0; j<=limit; j++) {
                if(dp[j][i] != -1) {
                    dp[i][j] = dp[j][i];
                    if(dp[i][j]==1) cnt++;
                }
                else{
                    long long thirdChild = n - i - j;
                    if(thirdChild>=0 && thirdChild<=limit) {
                        dp[i][j] = 1;
                        cnt++;
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return cnt;
    }
};