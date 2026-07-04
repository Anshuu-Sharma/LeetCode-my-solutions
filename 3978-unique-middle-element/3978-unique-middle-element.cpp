class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];


        int midElement = nums[n/2];

        for(int i = 0; i<n; i++){
            if(i == n/2) continue;
            if(nums[i] == midElement) return false;
        }
        return true;

        
    }
};