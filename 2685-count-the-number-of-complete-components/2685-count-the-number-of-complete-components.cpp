class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> edge_count;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        // Path compression
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Merge root_j into root_i
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            edge_count[root_i] += edge_count[root_j] + 1;
        } else {
            // Same component, just add the edge
            edge_count[root_i]++;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        edge_count.resize(n, 0);

        // Initialize each node as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Union vertices based on edges
        for (const auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        int complete_components = 0;
        
        // Evaluate each standalone component
        for (int i = 0; i < n; ++i) {
            // Check if 'i' is a root node of a component
            if (parent[i] == i) {
                int v = size[i];
                int e = edge_count[i];
                
                // A complete graph has v * (v - 1) / 2 edges
                if (e == v * (v - 1) / 2) {
                    complete_components++;
                }
            }
        }

        return complete_components;
    }
};