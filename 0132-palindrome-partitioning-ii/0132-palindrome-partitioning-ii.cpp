class Solution {
public:
    // bool isPalindrome(string s) {
    //     int i = 0;
    //     int j = s.size()-1;
    //     while(i<=j) {
    //         if(s[i] != s[j]) return false;
    //         i++;j--;
    //     }
    //     return true;
    // }
    // int helper(int ind, string s, vector<int>& dp) {
    //     if(ind == s.size()) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     string temp = "";
    //     int minPart = INT_MAX;

    //     for(int i = ind; i<s.size(); i++) {
    //         temp+=s[i];
    //         if(isPalindrome(temp)) {
    //             int part = 1 + helper(i+1, s, dp);
    //             minPart = min(minPart, part);
    //         }
    //     }
    //     return dp[ind] = minPart;
    // }

    bool isPalindrome(const string& s, int l, int r) {
    while(l < r) {
        if(s[l++] != s[r--]) return false;
    }
    return true;
}
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        // return helper(0, s, dp)-1;

        for(int ind = n-1; ind>=0; ind--) {
            string temp = "";
            int minPart = INT_MAX;

            for(int i = ind; i<n; i++) {
                temp+=s[i];
                if(isPalindrome(s,ind, i)) {
                    int part = 1 + dp[i+1];
                    minPart = min(minPart, part);
                }
            }
            dp[ind] = minPart;
        }
        return dp[0]-1;
    }
};