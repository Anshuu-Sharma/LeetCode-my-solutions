// definining disjoing set and its functions

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<n; ++i) {
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
        if(size[fu] > size[fv]) {
            parent[fv] = fu;
            size[fu]+=size[fv];
        }
        else{
            parent[fu] = fv;
            size[fv]+=size[fu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        // making hashmap of mails along with their nodes they belong to ->(0,n-1)
        // and connecting those nodes which have same values so that they point to same ultimate parent(person)
        unordered_map<string, int> mpp;
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<accounts[i].size(); j++) {
                string s = accounts[i][j];
                if(mpp.find(s) != mpp.end()){
                    ds.unionBySize(i, mpp[s]);
                }
                else mpp[s] = i;
            }
        }

        vector<vector<string>> mergedMails(n);
        for(auto it:mpp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i<n; i++) {
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            // temp.push_back(mergedMails[i].begin(), mergedMails[i].end());
            temp.insert(temp.end(), mergedMails[i].begin(), mergedMails[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};