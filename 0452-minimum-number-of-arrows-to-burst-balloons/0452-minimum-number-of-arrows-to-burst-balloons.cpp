class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int cnt = 1;
        int l = points[0][0];
        int r = points[0][1];
        for(int i = 1; i<n; i++){
            int nl = points[i][0];
            int nr = points[i][1];
            if(r < nl) {
                cnt++;
                l = nl;
                r = nr;
            }
            l = max(l, nl);
            r = min(r, nr);
        }
        return cnt;
    }
};