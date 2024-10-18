class Solution {
private: 
    int maxi = 0;
    int cnt = 0;
        

public:
    void check(vector<int>& nums, int low, int n, int currentOR){
        if(low == n) {
            maxi = max(currentOR, maxi);
            return;
        }

        check(nums, low+1, n, nums[low] | currentOR);
        check(nums, low+1, n, currentOR);
    }

    void counter(vector<int>& nums, int low, int n, int currentOR){
        if(low == n) {
            if(currentOR == maxi) cnt++;
            return;
        }

        counter(nums, low+1, n, nums[low] | currentOR);
        counter(nums, low+1, n, currentOR);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        check(nums, 0, n, 0);
        counter(nums, 0, n, 0);
        return cnt;

    }
};