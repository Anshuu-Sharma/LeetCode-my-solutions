class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);

        //even
        if(n%2 == 0){
            for(int i = 0; i<n/2; i++){
                ans[i] = -1*(i+1);
                ans[n-i-1] = i+1;
            }
        }

        //odd
        else{
            for(int i = 0; i<n/2; i++){
                ans[i] = -1*(i+1);
                ans[n-i-1] = i+1;
            }
            ans[n/2] = 0;
        }

        return ans;
    }
};