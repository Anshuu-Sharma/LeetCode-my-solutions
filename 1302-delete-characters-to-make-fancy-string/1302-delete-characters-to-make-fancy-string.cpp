class Solution {
public:
    string makeFancyString(string s) {
    if(s.length()<3) {
        return s;
    }
    int j = 2;
    for (int i = 2; i < s.size(); ++i)
        if (s[i] != s[j - 1] || s[i] != s[j - 2])
            s[j++] = s[i];
    s.resize(j);
    return s;
}
    // string makeFancyString(string s) {
    //     string ans = "";
    //     for (char& c : s) {
    //         int n = ans.size();
    //         if (n < 2 || ans[n - 1] != c || ans[n - 2] != c) {
    //             ans += c;
    //         }
    //     }
    //     return ans;
    // }
};