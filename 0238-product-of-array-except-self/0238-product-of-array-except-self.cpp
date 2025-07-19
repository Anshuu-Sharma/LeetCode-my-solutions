class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int zeros = 0;
        int prod = 1;
        int ind = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                ind = i;
                zeros++;
                if(zeros>1) return ans;
            }
            else prod *= nums[i];
        }

        if(zeros==1) ans[ind] = prod;
        else{
            for(int i = 0; i<n; i++){
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};