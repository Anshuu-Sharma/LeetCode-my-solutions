class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int loc=nums.size();
        int low = 0, high = nums.size() - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){
                loc = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return loc;
    }
};