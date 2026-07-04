class DisJointSet{
public:
    vector<int> parent, size;
    DisJointSet(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }

    int ultParent(int u){
        if(parent[u] == u) return u;

        return parent[u] = ultParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ultPar1 = ultParent(u);
        int ultPar2 = ultParent(v);

        if(ultPar1 == ultPar2) return;

        else if(ultPar1 < ultPar2){
            parent[ultPar1] = ultPar2;
            size[ultPar2] += size[ultPar1];
        }
        else{
            parent[ultPar2] = ultPar1;
            size[ultPar1] += size[ultPar2];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSet ds(n);

        // making the disjoint set here of those nodes which are connected
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                if(isConnected[i][j]) ds.unionBySize(i,j);
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(ds.ultParent(i) == i) cnt++; 
        }

        return cnt;


    }
};