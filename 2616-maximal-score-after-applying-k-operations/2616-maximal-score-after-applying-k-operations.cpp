class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> max_heap(nums.begin(), nums.end());

        while (k > 0) {
            int max_element = max_heap.top();
            max_heap.pop();
            ans += max_element;
            max_heap.push(ceil(max_element / 3.0));  // Avoid integer division
            k--;
        }

        return ans;
    }
};