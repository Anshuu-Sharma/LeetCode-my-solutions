class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int cnt = 0;
        int n = s.size();
        int a = n-1;
        while( s[a] == ' ') a--;

        for (int i = a; i >= 0; i--) {
                if (s[i] != ' ') cnt++;

            else if (s[i] == ' ') return cnt;

            
        }
        return cnt;
     }
};