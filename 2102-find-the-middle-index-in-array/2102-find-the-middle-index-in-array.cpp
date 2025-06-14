class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);

        for(int i = 1; i<n; i++) {
            leftSum[i] = leftSum[i-1] + nums[i-1];
            rightSum[n-i-1] = rightSum[n-i] + nums[n-i];
        }

        for(int i = 0; i<n; i++) {
            if(leftSum[i] == rightSum[i]) return i;
        }
        return -1;

    }
};