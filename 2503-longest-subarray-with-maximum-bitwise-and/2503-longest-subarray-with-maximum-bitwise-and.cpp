class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int currLen = 0;
        int maxInd = 0;

        int i = 0;
        int n = nums.size();
        while(i<n) {
            if(nums[i] > nums[maxInd]) {
                maxInd = i;
                currLen = 1;
                maxLen = 1;
            }

            else if(nums[i] == nums[maxInd]){
                maxLen = max(maxLen, ++currLen);
            }
            else currLen = 0;
            i++;
        }

        return maxLen;

    }
};