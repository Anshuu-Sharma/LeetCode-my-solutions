class Solution {
public:
int f(vector<int>& nums, int goal) {
        int l = 0 , r = 0, cnt = 0;
        long long sum1 = 0; 
        while(r<nums.size()) {
            sum1 += nums[r]%2;
            while(sum1 > goal) {
                sum1 -= nums[l]%2;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
         return f(nums, k) - f(nums, k-1);
    }
};