class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int ind = -1;
        int low = 0;
        int high = n-1;

        while(low<=high) {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) {
                ind = mid;
                high = mid-1;
            }
             else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(ind == -1) return ans;
        while(ind < n && nums[ind] == target){
            ans.push_back(ind);
            ind++;
        } 
        return ans;
    }
};