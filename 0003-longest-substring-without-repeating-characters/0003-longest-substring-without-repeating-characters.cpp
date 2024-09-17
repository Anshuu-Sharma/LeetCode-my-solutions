class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> hash(256,-1);
        int l = 0, r = 0;int n = s.size();
        int maxlen = 0;int len = 0;
        while(r<n) {
            if(hash[s[r]] != -1) {
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
          len = r - l + 1;
           maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};