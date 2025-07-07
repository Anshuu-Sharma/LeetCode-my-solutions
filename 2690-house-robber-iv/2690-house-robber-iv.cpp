class Solution {
public:
    bool isCapabilityPoss(vector<int>& nums, int k , int mid) {
        int cnt = 0;

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] <= mid) {
                cnt++;
                i++;
            }
            if(cnt == k) return true;
        }

        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = ranges::min(nums);
        int high = ranges::max(nums);
        int ans = 0;

        while(low<=high) {
            int mid = low + (high - low)/2;

            if(isCapabilityPoss(nums, k, mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }

        return ans;
        
    }
};