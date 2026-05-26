class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]] = i;
        }

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mpp[nums[mid]];
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return -1;
    }
};