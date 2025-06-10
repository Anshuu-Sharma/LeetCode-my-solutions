class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prod = 1;
        int zero = false;

        vector<int> zeroInd;
        vector<int> ans(n,0);

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                zero = true;
                zeroInd.push_back(i);
            }
            else prod *= nums[i];
        }

        if(zeroInd.size() > 1) prod = 0;
        if(zero) {
            for(auto it:zeroInd) {
                ans[it] = prod;
            }
            return ans;
        }

        for(int i = 0; i<n; i++) {
            ans[i] = prod/nums[i];
        }

        return ans;


    }
};