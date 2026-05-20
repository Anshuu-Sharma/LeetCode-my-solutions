class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        int prefixSum = 0;
        mpp[0] = 1;
        int cnt = 0;
        
        for(int i = 0; i<nums.size(); i++){
            prefixSum += nums[i];
            int remainder =  prefixSum - k;
            cnt += mpp[remainder];
            mpp[prefixSum]++;
        }

        return cnt;
    }
};