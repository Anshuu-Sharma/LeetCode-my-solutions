class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> first_idx, last_idx, freq;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (first_idx.find(x) == first_idx.end()) {
                first_idx[x] = i;
            }
            last_idx[x] = i;
            freq[x]++;
        }
        
        int special_count = 0;
        for (auto& [x, count] : freq) {
            if (last_idx[x] - first_idx[x] + 1 == count) {
                special_count++;
            }
        }
        
        return special_count;
    }
};