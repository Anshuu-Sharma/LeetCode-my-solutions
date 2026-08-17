class Solution {
public:
    int longestSubstring(string s, int k) {
        // divide and coquer
        int n = s.length();
        
        // Base cases
        if (n == 0 || n < k) return 0;
        
        // Count the frequency of each character in the current string
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Find the first character that appears less than 'k' times i.e. invalid char
        int i = 0;
        while (i < n && count[s[i] - 'a'] >= k) {
            i++;
        }
        
        // If all characters appear at least k times, the whole string is valid
        if (i == n) return n;
        
        // Otherwise, split the string at this invalid character and recurse on the left half
        int left = longestSubstring(s.substr(0, i), k);
        
        // Skip any adjacent invalid characters to avoid unnecessary splits
        while (i < n && count[s[i] - 'a'] < k) {
            i++;
        }
        
        // Recurse on the right half
        int right = longestSubstring(s.substr(i), k);
        
        // The longest valid substring is the max of the left and right segments
        return max(left, right);
    }
};