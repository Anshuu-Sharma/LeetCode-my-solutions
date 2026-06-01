class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // If s1 is longer than s2, it can't be a substring
        if (n > m) return false;
        
        vector<int> s1_freq(26, 0);
        vector<int> window_freq(26, 0);
        
        // Populate frequencies for s1 and the very first window of s2
        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
            window_freq[s2[i] - 'a']++;
        }
        
        // Check if the first window happens to be a match
        if (s1_freq == window_freq) return true;
        
        // Slide the window across the rest of s2
        for (int i = n; i < m; i++) {
            // Add the new character entering the window on the right
            window_freq[s2[i] - 'a']++;
            
            // Remove the old character left behind by the window
            window_freq[s2[i - n] - 'a']--;
            
            // Check if our updated window matches s1's character frequencies
            if (s1_freq == window_freq) return true;
        }
        
        return false;
    }
};