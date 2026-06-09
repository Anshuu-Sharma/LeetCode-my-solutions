class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        DisjointSet ds(m * n + 1);
        int dummy = m * n;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
            
            // 1. If it's a boundary, connect to dummy
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                ds.unionBySize(i * n + j, dummy);
            } 
            
            // 2. EVERY 'O' cell (boundary or not) looks Top and Left
            // Look Top
            if (i > 0 && board[i - 1][j] == 'O') {
                ds.unionBySize(i * n + j, (i - 1) * n + j);
            }
            // Look Left
            if (j > 0 && board[i][j - 1] == 'O') {
                ds.unionBySize(i * n + j, i * n + (j - 1));
            }
        }
    }
}

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && ds.findUPar(i * n + j) != ds.findUPar(dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};