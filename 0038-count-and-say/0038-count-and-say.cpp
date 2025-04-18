class Solution {
 public:
 //KNK
  string countAndSay(int n) {
    string ans = "1";
    while (--n > 0) {
      string next;
      for (int i = 0; i < ans.length(); ++i) {
        int checkk = 1;
        while (i + 1 < ans.length() && ans[i] == ans[i + 1]) {
          ++checkk;
          ++i;
        }
        next += to_string(checkk) + ans[i];
      }
      ans = std::move(next);
    }
    return ans;
  }
};
