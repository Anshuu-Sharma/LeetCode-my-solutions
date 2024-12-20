class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0;
        sort(points.begin(), points.end());

       for (int i = 1; i < points.size(); i++) {
            int temp = points[i][0] - points[i-1][0];
            ans = max(temp , ans);
       }
       return ans;
    }
};