class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stops = 0;
        int curr = startFuel;
        int i = 0;
        int n = stations.size();
        
        while (curr < target) {
            while (i < n && stations[i][0] <= curr) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if (pq.empty()) {
                return -1;
            }
            
            curr += pq.top();
            pq.pop();
            stops++;
        }
        
        return stops;
    }
};