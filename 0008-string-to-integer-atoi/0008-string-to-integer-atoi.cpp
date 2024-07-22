class Solution {
public:
    int myAtoi(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;
        int n = s.size();
        
        // Step 1: Remove leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        bool neg = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            neg = (s[i] == '-');
            i++;
        }

        // Step 3: Convert digits to integer
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');   // yaha zero agar aaega leading mein then also it adds 0 to ans;
            // Check for overflow and underflow
            if (ans > INT_MAX) {
                return neg ? INT_MIN : INT_MAX;
            }
            i++;
        }

        return neg ? -ans : ans;
    }
};