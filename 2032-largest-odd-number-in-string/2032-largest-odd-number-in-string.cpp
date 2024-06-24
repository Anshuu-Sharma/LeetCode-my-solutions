class Solution {
public:
    string largestOddNumber(string num) {
        stack<char> stk;
        for(int i = 0; i<num.size(); i++) {
            stk.push(num[i]);
        }

        if(stk.top() % 2 != 0) return num;
        string ans = "";    
        while(!stk.empty()) {
            if((stk.top() % 2) == 0) stk.pop();
            else {
                while(!stk.empty()) {
                    ans.insert(0,1,stk.top());
                    stk.pop();
                }
            }
        }

        
        return ans;
    }
};