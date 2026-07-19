class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ops = 0;
        int l = 0;
        int r = n-1;

       while(l<r){
        if(nums[l] + nums[r] == k){
            ops++;
            l++;
            r--;
        }
        else if(nums[l] + nums[r] > k){
            r--;
        }
        else l++;
       }

       return ops;
    }
};