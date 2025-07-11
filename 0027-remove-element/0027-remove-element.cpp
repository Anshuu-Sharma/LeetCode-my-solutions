class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Points to the next position to write a non-val element
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
