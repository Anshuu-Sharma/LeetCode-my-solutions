class DSU {
public:
    vector<int> parent;
    vector<long long> size; // Use long long to prevent overflow during multiplication later

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initially, every node is its own component of size 1
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            // Union by size to keep the tree shallow
            if(size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY]; // Add the size of the smaller component to the larger one
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        
        // Step 1: Build the components
        for(auto& edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }

        long long ans = 0;
        long long remaining_nodes = n;

        // Step 2 & 3: Find unique components and calculate unreachable pairs
        for(int i = 0; i < n; i++) {
            // If a node is its own parent, it is the ultimate root of a unique component
            if(dsu.parent[i] == i) { 
                long long current_size = dsu.size[i];
                
                // Subtract the current component's size from the remaining pool
                remaining_nodes -= current_size;
                
                // Multiply the size of the current component by the remaining nodes
                ans += current_size * remaining_nodes;
            }
        }

        return ans;
    }
};