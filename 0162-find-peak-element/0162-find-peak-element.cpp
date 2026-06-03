class Solution {
public:
    int helper(int l, int r, vector<int>& nums) {
        if (l == r) return l;

        int mid = (l + r) / 2;

        if (nums[mid] > nums[mid + 1])
            return helper(l, mid, nums); 
        else
            return helper(mid + 1, r, nums); 
    }

    int findPeakElement(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums);
    }
};
