class Solution {
public:

    bool check(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for(string it : words){
            if(check(it)) return it;
        }
        return "";
    }
};