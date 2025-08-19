class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     long long ans = 0;
     long long n = nums.size();
     long long l = 0;
      long long r = 0;
     for(long long i = 0; i<n; i++){
        if(nums[i] == 0){
            long long len = 0;
            while(i<n &&nums[i] == 0) {
                len++;
                i++;
            }
            ans += (len*(len+1))/2;
        }
      }   
        return ans;
    }
};