class DisjointSet {
public:
    // making DisjointSet data strucutre
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<n; ++i){
            parent[i] = i;
        }
    }

    int findUPar(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findUPar(parent[x]);
    }

    void unionBySize(int u, int v) {
        int fu = findUPar(u);
        int fv = findUPar(v);

        if(fu == fv) return;
        if(size[fu]>size[fv]) {
            parent[fv] = fu;
            size[fu]+=size[fv];
        }
        else {
            parent[fu] = fv;
            size[fv]+=size[fu];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        //finding maximum rows and cols
        int maxRow = 0;
        int maxCol = 0;

        for(auto it:stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // usedNodes contains those nodes which were used to make components only
        unordered_map<int,int> usedNodes;
        DisjointSet ds(maxCol+maxRow+2);

        for(auto it:stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);
            usedNodes[nodeRow] = 1;
            usedNodes[nodeCol] = 1;
        }

        // counting components
        int cntComponents = 0;
        for(auto it:usedNodes) {
            if(ds.findUPar(it.first) == it.first) cntComponents++;
        }
        return n-cntComponents;
    }
};