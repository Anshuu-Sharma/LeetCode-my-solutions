class DisJointSet{
public:
    vector<int> parent, size;

    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int x){
        if(x == parent[x]) return x;
        return parent[x] = findUPar(parent[x]);
    }

    void unionBySize(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pv == pu) return;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisJointSet ds(n);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                return {u,v};
            }

            ds.unionBySize(u, v);
        }

        return{};
    }
};