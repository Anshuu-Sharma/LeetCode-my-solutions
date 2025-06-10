class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;

        if(n==1) return 0;

        if(n == 2) {
            int diff = abs(nums[0]-nums[1]);
            return diff == k ? 1:0;
        }

       int prev1 = 1e9;
       int prev2 = 1e9; 


        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                int diff = abs(nums[i] - nums[j]);
                if(diff == k) {
                    if(prev1 == 1e9 && prev2 == 1e9) {
                        prev1 = nums[i];
                        prev2 = nums[j];
                        cnt++;
                    }
                    else if(prev1 != 1e9 && prev2 != 1e9) {
                        if(prev1 == nums[i]) break;
                        else {
                            prev1 = nums[i];
                            prev2 = nums[j];
                            cnt++;
                        } 
                    }
                }
                else if(diff > k) break;
            }
        }
        return cnt;
    }
};
