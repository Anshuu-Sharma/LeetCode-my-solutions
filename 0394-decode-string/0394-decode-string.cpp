class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i<n; i++) {
            if(s[i] != ']') st.push(s[i]);
            else {
                string subst = "";
                while(st.top() != '[') {
                    subst = st.top() + subst;
                    st.pop();
                }

                st.pop();

                string k = "";
                while(!st.empty() && isdigit(st.top())) {
                    k = st.top() + k;
                    st.pop();
                }

                int num = stoi(k);
                string temp;
                for (int j = 0; j < num; j++) {
                    temp += subst;
                }
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};