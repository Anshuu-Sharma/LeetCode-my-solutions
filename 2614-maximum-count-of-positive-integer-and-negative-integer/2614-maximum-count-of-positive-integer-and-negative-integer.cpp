class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int negcnt = 0;
        int zeroCount = 0;
        while(i<n && nums[i]<=0){
            if(nums[i] == 0) {
                zeroCount++;
                i++;
            }
           else{
                negcnt++;
                i++;
           }
        }
        return max(negcnt, (n-negcnt-zeroCount));









        // Brute Force Approach
        // int pos , neg = 0;
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] > 0) pos++;
        //     if(nums[i] < 0) neg++;
        // }
        // return max(pos, neg);
    }
};