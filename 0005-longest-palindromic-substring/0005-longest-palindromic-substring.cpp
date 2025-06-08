class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int ansLen = 0;

        for(int i = 0; i<s.size(); i++) {
            // odd length palindromes
            int l = i, r = i;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                if((r-l+1) > ansLen){
                    ansLen = r-l+1;
                    ans = s.substr(l,ansLen);
                }
                l--;r++;
            }

            // even length palindromes
            l = i,r = i+1;
             while(l>=0 && r<s.size() && s[l] == s[r]){
                if((r-l+1) > ansLen){
                    ansLen = r-l+1;
                    ans = s.substr(l,ansLen);
                }
                l--;r++;
            }
        }

        return ans;
    }
};