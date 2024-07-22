class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int maxi = 0;
        for(int i = 0 ;i<s.size(); i++) {
            if(s[i] == '(') {
                stk.push('(');
                int s =  stk.size();
                maxi = max(maxi, s);
            }
            if(s[i] == ')'){
                stk.pop();
            }
        }
        return maxi;
    }
};