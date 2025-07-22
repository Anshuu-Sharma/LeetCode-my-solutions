class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxSum = 0;
        int maxi = 0;
        unordered_set<int> st;

        while(j<n){
            if(st.count(nums[j]) == 0){
                st.insert(nums[j]);
                maxSum += nums[j];
                j++;
                maxi = max(maxi, maxSum);

            }
            else{
                while(st.count(nums[j]) != 0){
                    maxSum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }

        return maxi;
    }
};