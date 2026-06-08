#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap to store {max_elevation_so_far, {row, col}}
        // greater<> ensures the smallest max_elevation_so_far is at the top.
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Keep track of visited cells to prevent cycles
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start at the top-left corner
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        // Directions for moving 4-directionally (up, down, left, right)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            
            // If we've reached the bottom-right corner, return the time
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            
            // Explore all 4 valid neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check boundaries and if it's already visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The time required to reach the neighbor is the max of 
                    // the path's current maximum time and the neighbor's elevation.
                    pq.push({max(time, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        
        return -1; 
    }
};