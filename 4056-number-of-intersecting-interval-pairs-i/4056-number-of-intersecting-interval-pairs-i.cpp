class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int s1 = intervals[i][0];
                int e1 = intervals[i][1];
                int s2 = intervals[j][0];
                int e2 = intervals[j][1];

                if(s1<=e2 && s2<=e1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};