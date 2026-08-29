class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int val : nums2) {
            freq2[val]++;
        }
    }
    
    void add(int index, int val) {
        int old_val = nums2[index];
        freq2[old_val]--;
        
        nums2[index] += val;
        int new_val = nums2[index];
        freq2[new_val]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            int target = tot - x;
            if (freq2.count(target)) {
                ans += freq2[target];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */