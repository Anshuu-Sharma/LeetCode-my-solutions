class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int l = 0;
        int r = 0;
        while(r < s.size() && l < g.size()){
            if(g[l] <= s[r]) {
                cnt++;
                l++;
                r++;
            }
            else r++;
        }
        return cnt;
    }
};