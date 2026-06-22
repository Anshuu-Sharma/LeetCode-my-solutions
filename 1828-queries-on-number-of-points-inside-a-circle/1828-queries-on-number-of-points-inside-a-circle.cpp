class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer;
        answer.reserve(queries.size()); // Optimize memory allocation
        
        for (const auto& query : queries) {
            int cx = query[0];
            int cy = query[1];
            int r = query[2];
            int r_squared = r * r; // Calculate radius squared once per query
            int count = 0;
            
            for (const auto& point : points) {
                int px = point[0];
                int py = point[1];
                
                // Calculate squared distance from point to circle center
                int dx = px - cx;
                int dy = py - cy;
                
                // If squared distance is <= radius squared, point is inside
                if (dx * dx + dy * dy <= r_squared) {
                    count++;
                }
            }
            answer.push_back(count);
        }
        
        return answer;
    }
};