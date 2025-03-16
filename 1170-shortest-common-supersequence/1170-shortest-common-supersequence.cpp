class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        // main loop
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                // if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
                if(str1[ind1-1] == str2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];

                else dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }

        string ans = "";
        int i = n1;
        int j = n2;
        
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans+=str1[i-1];i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }

        // if strings is left in str1
        while(i>0){
            ans+=str1[i-1];i--;
        }
        //if strings are left in str2
        while(j>0){
            ans+=str2[j-1];j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};