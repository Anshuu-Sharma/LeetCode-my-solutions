class Solution {
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int min = 0, max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min++;
                max++;
            }
            else if (s[i] == ')') {
                min--;
                max--;
            }
            else {
                min--;
                max++;
            }
            if (min < 0) min = 0;
            if (max < 0) return false;
        }
       return min == 0;
    }
};