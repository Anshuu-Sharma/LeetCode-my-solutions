class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int ans = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] > prev){
                prev = nums[i];
                continue;
            }
            int diff = prev - nums[i];
            ans += diff + 1;
            prev = nums[i] + diff + 1;
        }
        return ans;
    }
};