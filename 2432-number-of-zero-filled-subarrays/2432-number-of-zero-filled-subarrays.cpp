class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     long long ans = 0;
     int n = nums.size();
     int l = 0;
     for(int i = 0; i<n; i++){
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