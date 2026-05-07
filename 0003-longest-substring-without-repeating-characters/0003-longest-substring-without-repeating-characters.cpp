class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashmap(256,-1);
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        while(r<n){
            if(hashmap[s[r]] != -1){
                if(hashmap[s[r]] >= l) l = hashmap[s[r]] + 1;
            }
            int len = r-l+1;
            hashmap[s[r]] = r;
            maxlen = max(len, maxlen);
            r++;
        }
        return maxlen;
    }
};