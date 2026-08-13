class Solution {
public:
    int balancedString(string s) {
        // as n is a multiple of 4, then freq will be like 1,2,3... for n = 4,8,12...
        // we need to find the minimum length substring to make that possible

        unordered_map<char, int> count;
        int n = s.length();
        int k = n / 4;
        
        // Count the frequency of each character in the string
        for (char c : s) {
            count[c]++;
        }
        
        // If it's already balanced, return 0
        if (count['Q'] == k && count['W'] == k && count['E'] == k && count['R'] == k) {
            return 0;
        }
        
        int ans = n;
        int left = 0;
        
        // Sliding window: [left, right] is the substring we are considering replacing
        for (int right = 0; right < n; ++right) {
            // Include s[right] in the window (remove from outside counts)
            count[s[right]]--;
            
            // If characters outside the window are all <= n/4, the window is valid
            while (left < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                ans = min(ans, right - left + 1);
                
                // Shrink the window from the left to find the minimum length
                count[s[left]]++;
                left++;
            }
        }
        
        return ans;
    }
};