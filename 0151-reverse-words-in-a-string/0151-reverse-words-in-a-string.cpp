class Solution {
public:
    void remove_spaces(string& s) {
       
            while(s[0] == ' ') s.erase(0,1);
            while(s[s.size()-1] == ' ') s.erase(s.size()-1, 1);

            for(int i = 1; i<s.size()-1; i++) {
                while(s[i] == ' ' && s[i+1] == ' ') s.erase(i,1);
            }
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        remove_spaces(s);
        string ans = "";
        string temp;
        int l = 0;
        int r;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == ' ') {
                r = i - 1;
                temp =  s.substr(l,(r-l+1)); 
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += ' ';
                l = i + 1;
            }
        }
        r = s.size()-1;
        temp = s.substr(l,(r-l+1));
        reverse(temp.begin(), temp.end());
         ans += temp;
        return ans;

 
 
    }
};