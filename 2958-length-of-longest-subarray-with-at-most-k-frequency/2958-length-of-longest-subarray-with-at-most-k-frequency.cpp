class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        int l = 0;
        int r = 0;
        // we can either have a map or a vector of size 10^5
        // vector<int> hash(1e9+2, 0); // we cant use vector as size is 1e9! so use map
        unordered_map<int, int> hash;
        while(r<n){
            hash[nums[r]]++;

            while(l<n && hash[nums[r]] > k) hash[nums[l++]]--;


            ans = max(ans, (r-l+1));
            r++;
        }

        return ans;
    }
};