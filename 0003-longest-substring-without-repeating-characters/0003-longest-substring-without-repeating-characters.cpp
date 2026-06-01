class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char, int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(l<r && mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }
            int len = r - l + 1;
            ans = max(ans, len);
            r++;
        }

        return ans;
    }
};