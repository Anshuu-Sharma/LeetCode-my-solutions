#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        // Path compression
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        
        if (rootI != rootJ) {
            parent[rootJ] = rootI;
        }
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        // Dummy node acts as our "rejection component"
        int dummy = m * n; 
        UnionFind uf(m * n + 1);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { // If it's land
                    int id = i * n + j;
                    
                    // If it's on the boundary, connect it to the rejection component
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        uf.unite(id, dummy);
                    }
                    
                    // Union with the top neighbor
                    if (i > 0 && grid[i-1][j] == 0) {
                        uf.unite(id, (i - 1) * n + j);
                    }
                    // Union with the left neighbor
                    if (j > 0 && grid[i][j-1] == 0) {
                        uf.unite(id, i * n + (j - 1));
                    }
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int id = i * n + j;
                    // It is a valid closed island if:
                    // 1. It is its own root (we only count the component once)
                    // 2. It is NOT connected to the dummy/rejection node
                    if (uf.find(id) == id && uf.find(id) != uf.find(dummy)) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};