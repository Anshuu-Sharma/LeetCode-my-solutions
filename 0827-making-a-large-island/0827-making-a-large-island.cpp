#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) class to manage connected components
class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    // Find with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    // Union by size
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // Attach smaller tree under larger tree
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    
    // Get the size of the component a node belongs to
    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        bool hasZero = false;
        
        // Step 1: Connect all adjacent 1s using Union-Find
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int id1 = r * n + c;
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int id2 = nr * n + nc;
                            dsu.unite(id1, id2);
                        }
                    }
                } else {
                    hasZero = true;
                }
            }
        }
        
        // If there are no zeros, the whole grid is one massive island
        if (!hasZero) return n * n;
        
        int maxArea = 0;
        
        // Step 2: Try flipping every '0' to '1' and calculate potential new area
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> neighboringRoots;
                    
                    // Find unique roots of adjacent islands
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            neighboringRoots.insert(dsu.find(nr * n + nc));
                        }
                    }
                    
                    // Calculate total area if we flipped this '0'
                    int potentialArea = 1; // Start with 1 for the flipped '0'
                    for (int root : neighboringRoots) {
                        potentialArea += dsu.getSize(root);
                    }
                    
                    maxArea = max(maxArea, potentialArea);
                }
            }
        }
        
        return maxArea;
    }
};