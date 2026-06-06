class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int totalBoomerangs = 0;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> distanceCount;
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int squaredDistance = dx * dx + dy * dy;
                
                distanceCount[squaredDistance]++;
            }
            
            for (auto const& [distance, count] : distanceCount) {
                totalBoomerangs += count * (count - 1);
            }
        }
        
        return totalBoomerangs;
    }
};