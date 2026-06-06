class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // monotonic increasing stack
        stack<int> st;
        vector<int> ans(k);
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Pop if top is LARGER than current, and we have enough 
            // elements remaining to still reach length k
            while (!st.empty() && st.top() > nums[i] && (st.size() + (n - i) > k)) {
                st.pop();
            }
            
            // Push current if we haven't reached size k
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }
        
        int cnt = k-1;
        while(cnt >= 0 && !st.empty()){
            ans[cnt] = st.top(); st.pop();
            cnt--;
        }
        return ans;
    }
};