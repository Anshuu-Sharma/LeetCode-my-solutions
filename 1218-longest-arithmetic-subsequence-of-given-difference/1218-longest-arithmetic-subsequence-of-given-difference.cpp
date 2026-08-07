class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int x : arr) {
            // The length of the sequence ending at 'x' is 1 + length of the sequence ending at 'x - difference'
            dp[x] = dp[x - difference] + 1;
            
            // Keep track of the maximum length found so far
            max_len = max(max_len, dp[x]);
        }
        
        return max_len;
    }
};