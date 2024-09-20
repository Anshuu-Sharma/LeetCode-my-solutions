class Solution {
public:
    static bool comp(const vector<int>& val1,const vector<int>& val2) {
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        std::sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int cnt = 1;
        int lastendtime = intervals[0][1];
        for(int i = 1; i<n; i++) {
            if(intervals[i][0] >= lastendtime) {
                cnt++;
                lastendtime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};