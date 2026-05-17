class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        unordered_map<int,int> mpp;

        int maxi_len = 0;
        mpp[0] = -1;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0) sum--;
            else sum++;

            if(mpp.find(sum) != mpp.end()) maxi_len = max(maxi_len, i - mpp[sum]);
            else mpp[sum] = i;
        }

        return maxi_len;

    }
};