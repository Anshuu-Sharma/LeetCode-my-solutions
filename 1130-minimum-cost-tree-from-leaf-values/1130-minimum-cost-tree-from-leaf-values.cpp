class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        stack<int> st;
        st.push(INT_MAX); // sentinel so stack is never empty

        for (int a : arr) {
            while (st.top() <= a) {
                int mid = st.top();
                st.pop();
                result += mid * min(st.top(), a);
            }
            st.push(a);
        }

        // Merge remaining elements in stack
        int first = st.top(); st.pop();
        while (st.size() > 1) { // leave sentinel
            result += first * st.top();
            first = st.top();
            st.pop();
        }

        return result;
    }
};