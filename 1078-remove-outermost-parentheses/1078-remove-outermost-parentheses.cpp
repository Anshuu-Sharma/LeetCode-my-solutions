class Solution {
public:
    string removeOuterParentheses(string S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string res = "";
        int cnt = 0, start = 0, n = S.size();
        for (int i = 0; i < n; ++i) {
            (S[i] == '(') ? ++cnt : --cnt;
            if (cnt != 0) continue;
            res += S.substr(start + 1, i - start - 1);
            start = i + 1;
        }
        return res;
    }
};