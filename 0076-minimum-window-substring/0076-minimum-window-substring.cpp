class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int n = s.size();
        int m = t.size();
        int minlen = INT_MAX;
        // l = left index, r = right index of window, sindex = starting index of ans string, cnt = count of elemnent of t
        int l = 0, r = 0, sindex = -1, cnt = 0;

        // hash for string t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while (cnt == m) { 
                if((r - l + 1 ) < minlen){
                    minlen = r - l + 1;
                    sindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};