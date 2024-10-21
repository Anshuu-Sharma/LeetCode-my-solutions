class Solution {
public:

    string helper(string a, string b){
        string ans = "";
        int i = 0;
        while(i < a.size() && i < b.size()){
            if(a[i] == b[i]) {
                ans.push_back(a[i]);
                i++;
            }
            else break;
        }
        return ans;
    }
    string longestCommonPrefix(vector <string>& strs) {
        if(strs[0].size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string ans = "";
        ans = helper(strs[0], strs[1]);
        for(int i = 2; i<strs.size(); i++){
            ans = helper(ans, strs[i]);
        }
        return ans;

    }
};