class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent.resize(n);
        rank.assign(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){

        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rank[a]<rank[b]) swap(a,b);

        parent[b]=a;

        if(rank[a]==rank[b]) rank[a]++;

        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size(),m=grid[0].size();

        DSU dsu(n*m);

        int count=0;

        int dr[2]={1,0};
        int dc[2]={0,1};

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]=='1'){

                    count++;

                    for(int k=0;k<2;k++){

                        int ni=i+dr[k];
                        int nj=j+dc[k];

                        if(ni<n && nj<m && grid[ni][nj]=='1'){

                            if(dsu.unite(i*m+j,ni*m+nj))
                                count--;
                        }
                    }
                }
            }
        }

        return count;
    }
};