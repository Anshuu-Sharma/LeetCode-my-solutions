class Solution {
public:
    string helper(string s){
        string new_s = "";
        int ind = 0;
        for(int i = 0; i<s.size()-1; i++) {
            new_s.push_back(((s[i] - '0') + (s[i+1]-'0')) % 10);
        }
        return new_s;
    }
    bool hasSameDigits(string s) {

        while(s.size()>2){
            s = helper(s);
        }
        return (s[0] == s[1]) ? true : false;
    }
};