class Solution {
public:
    int mod=1e9+7;
    int dp[100002][2][3][2];
    long long f(int i,int n,int l,int e,int t){
        if(i>n){
            if(l==0 and e==0 and t==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][l][e][t]!=-1){
            return dp[i][l][e][t]%mod;
        }
        long long cnt=0;
        for(char ch='a';ch<='z';ch++){
            if(ch=='l'){
                cnt=(cnt%mod+f(i+1,n,max(0,l-1),e,t)%mod)%mod;
            }
            else if(ch=='e'){
                cnt=(cnt%mod+f(i+1,n,l,max(0,e-1),t)%mod)%mod;
            }
            else if(ch=='t'){
                cnt=(cnt%mod+f(i+1,n,l,e,max(0,t-1))%mod)%mod;
            }
            else{
                cnt=(cnt%mod+f(i+1,n,l,e,t)%mod)%mod;
            }
        }
        return dp[i][l][e][t]=cnt%mod;
    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        long long ans=f(1,n,1,2,1)%mod;
        return ans%mod;
    }
};