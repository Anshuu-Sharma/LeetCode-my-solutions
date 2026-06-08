#include <vector>
#include <numeric>

using namespace std;

// Standard Union-Find structure with path compression and union by size
class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        // Initialize each element as its own parent
        iota(parent.begin(), parent.end(), 0); 
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            // Union by size
            if (size[rootI] < size[rootJ]) swap(rootI, rootJ);
            parent[rootJ] = rootI;
            size[rootI] += size[rootJ];
        }
    }
    
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];
        
        // Map elevation -> {row, col}
        vector<pair<int, int>> pos(n * n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                pos[grid[r][c]] = {r, c};
            }
        }
        
        UnionFind uf(n * n);
        vector<vector<bool>> unlocked(n, vector<bool>(n, false));
        
        // Directions for moving 4-directionally
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Process cells in increasing order of time (elevation)
        for (int t = 0; t < n * n; ++t) {
            int r = pos[t].first;
            int c = pos[t].second;
            
            // Submerge the current cell
            unlocked[r][c] = true;
            
            // Convert 2D coordinate to 1D index for Union-Find
            int current_idx = r * n + c;
            
            // Check all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // If the neighbor is within bounds and already unlocked, unite them
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && unlocked[nr][nc]) {
                    int neighbor_idx = nr * n + nc;
                    uf.unite(current_idx, neighbor_idx);
                }
            }
            
            // Check if start (0) and end (n*n - 1) are connected
            if (uf.connected(0, n * n - 1)) {
                return t;
            }
        }
        
        return -1;
    }
};