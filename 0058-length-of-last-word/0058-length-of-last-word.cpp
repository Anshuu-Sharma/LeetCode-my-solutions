class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int n = s.size();
        int a = n-1;
        while(s[a] == ' ') {
            a--;
        }
        for(int i = a; i>=0; i--) {
                if(s[i] != ' ') cnt++;

            else if(s[i] == ' ') return cnt;

            
        }
        return cnt;
     }
};