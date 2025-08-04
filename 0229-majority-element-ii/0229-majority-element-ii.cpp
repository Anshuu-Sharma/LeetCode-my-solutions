class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> ans;
        int n = nums.size();
        int k = (int)n/3 + 1;
        int cnt = 0;
        int i = 0;
        while(i<n){
            int num = nums[i];
            while(i<n && nums[i] == num){
                cnt++;
                i++;
            }
            if(cnt >= k) ans.push_back(num);
            // i++;
            cnt = 0;
        }
        return ans;
    }
};