class Solution {
public:
    int helper(int ind, string s,unordered_map<string, char>& numToChar, vector<int> &dp) {
        if(ind == s.size()) return 1;
        if(ind > s.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int cnt = 0;
        string oneChar = s.substr(ind, 1);
        if (numToChar.find(oneChar) != numToChar.end()) {
            cnt += helper(ind + 1, s, numToChar, dp);
        }

        if (ind + 1 < s.size()) {
            string twoChar = s.substr(ind, 2);
            if (numToChar.find(twoChar) != numToChar.end()) {
                cnt += helper(ind + 2, s, numToChar, dp);
            }
        }

        return dp[ind] = cnt;
    }
    int numDecodings(string s) {
        unordered_map<string, char> numToChar;

        for (int i = 1; i <= 26; ++i) {
            numToChar[to_string(i)] = 'A' + (i - 1);
        }

        int n = s.size();
        // vector<int> dp(n, -1);
        // return helper(0, s, numToChar, dp);

        // Bottom up approach
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] == '0') ? 0 : 1;

        for(int i = n-2; i>=0; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            dp[i] += dp[i+1];

            int num = stoi(s.substr(i, 2));
            if(num>=10 && num<=26) {
                dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};