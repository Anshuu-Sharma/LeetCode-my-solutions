class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < k) k = k % nums.size();

        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i<=(n-k-1); i++) {
            temp.push_back(nums[i]);
        }

        for(int i = n-k; i<n; i++) {
            nums[i-(n-k)] = nums[i];
        }

        for(int i = k; i<n; i++) {
            nums[i] = temp[i-k];
        
        }

        
    }
};