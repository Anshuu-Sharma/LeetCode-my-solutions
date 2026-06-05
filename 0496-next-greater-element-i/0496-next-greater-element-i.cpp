class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // first find next greater element of nums 2
        unordered_map<int, int> mpp;
        stack<int> st;

        int n2 = nums2.size();
        for(int i = n2-1; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            // If stack is empty, no greater element exists
    if (st.empty()) {
        mpp[nums2[i]] = -1;
    } else {
        // Otherwise, top is the next greater
        mpp[nums2[i]] = st.top();
    }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int num : nums1) {
            if (mpp.count(num)) {
                ans.push_back(mpp[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;

    }
};