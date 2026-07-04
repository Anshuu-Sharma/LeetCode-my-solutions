class Solution {
public:
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

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        DisjointSet ds(n);

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            // skip duplicates
            if(mpp.find(nums[i]) != mpp.end()) continue;

            // check num - 1
            if(mpp.find(nums[i] - 1) != mpp.end()) {
                ds.unionBySize(i, mpp[nums[i] - 1]);
            }

            // check num + 1
            if(mpp.find(nums[i] + 1) != mpp.end()) {
                ds.unionBySize(i, mpp[nums[i] + 1]);
            }

            mpp[nums[i]] = i;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }

        return ans;
    }
};