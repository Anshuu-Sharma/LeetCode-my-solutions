class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n * m);

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(grid[row][col] == 0) continue;


                // converting every element of the 2d graph into 1d unique nodes because DJS works on 1d nodes and not 2d matrices
                int node = row * m + col;

                for(int k = 0; k < 4; k++) {

                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if(nrow >= 0 && nrow < n &&
                       ncol >= 0 && ncol < m &&
                       grid[nrow][ncol] == 1) {

                        int adjNode = nrow * m + ncol;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int maxi = 0;

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(grid[row][col] == 1) {

                    int node = row * m + col;

                    int parent = ds.findUPar(node);

                    maxi = max(maxi, ds.size[parent]);
                }
            }
        }

        return maxi;
    }
};

