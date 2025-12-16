class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force would be O(n2)
        // unordered_set method is O(nlogn)
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]] = i;
        }

        for(int i = 0; i<n; i++){
            int left = target - nums[i];
            if(mpp.find(left) != mpp.end()) {
                if(mpp[left] != i) return {mpp[left], i};
                continue;
            }
        }

        return {};
    }
};