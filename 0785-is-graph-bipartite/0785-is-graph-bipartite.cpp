//Union Find
class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) continue;

            // All neighbors should belong to the same group, different from node i
            for (int j = 1; j < graph[i].size(); ++j) {
                uf.unite(graph[i][0], graph[i][j]);
            }

            // If i and its neighbor belong to same group → Not bipartite
            if (uf.find(i) == uf.find(graph[i][0]))
                return false;
        }

        return true;
    }
};