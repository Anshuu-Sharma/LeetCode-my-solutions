class Solution {
public:
    /*
imp1. in probs of exactly k, we often use atmost(k) - atmost(k-1)
imp2. number of valid subarrays for a window [l....r] is r-l+1 in which atmost(k) condition satisfies 

Suppose:

left = 3
right = 7

Current valid window:

[3 4 5 6 7]

All valid subarrays ending at index 7:

[7]
[6,7]
[5,6,7]
[4,5,6,7]
[3,4,5,6,7]
total = 5

and,
Number of valid subarrays:

 = right - left + 1
  = 7 - 3 + 1
  = 5 

Why?

If the whole window is valid,
then every suffix of the window is also valid.
*/
     int f(vector<int> & nums, int k) {
        int l = 0 , r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while(r < nums.size()) {
            mpp[nums[r]]++;
            while(mpp.size()>k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};