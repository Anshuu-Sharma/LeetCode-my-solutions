class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n,0);
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
    } 

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(up_u == up_v) return;

        if(rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        }
        else if(rank[up_u] < rank[up_v]) parent[up_u] = up_v;
        else {
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(up_u == up_v) return;

        if(size[up_u] > size[up_v]) {
            parent[up_v] = up_u;
            size[up_u]+=size[up_v];
        }
        else {
            parent[up_u] = up_v;
            size[up_v]+=size[up_u];
        }
       
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        DisjointSet ds(n);
        int cntExtraEdges = 0;
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) cntExtraEdges++;
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntComponents = 0;
        for(int i = 0; i<n; i++) {
            if(ds.parent[i] == i) cntComponents++;
        }

        int ans = cntComponents-1;
        if(ans<=cntExtraEdges) return ans;
        return -1;
    }
};