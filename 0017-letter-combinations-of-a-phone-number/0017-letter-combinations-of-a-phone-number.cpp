class Solution {
public:
    vector<string> ans;
    void helper(int idx, string& digits, string& temp, unordered_map<char, string>& mpp) {
        if(idx >= digits.size()){
            ans.push_back(temp);  
            return;
        } 

        char ch = digits[idx];
        string str = mpp[ch];

        for(int i = 0; i<str.size(); i++) {
            temp.push_back(str[i]);
            helper(idx+1, digits, temp, mpp);
            temp.pop_back();
        }
    } 
    vector<string> letterCombinations(string digits) {
        ans.clear();
        int n = digits.size();
        if(n==0) return {};

        vector<string> s;

        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        string temp = "";
        helper(0, digits, temp, mpp);
        return ans;
    }
};