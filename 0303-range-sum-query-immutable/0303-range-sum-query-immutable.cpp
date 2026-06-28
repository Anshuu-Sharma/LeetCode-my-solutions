class NumArray {
private:
    vector<int> tree;
    int n;

    // Helper function to build the segment tree
    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = nums[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        // Recursively build the left and right children
        build(leftChild, start, mid, nums);
        build(rightChild, mid + 1, end, nums);
        
        // Internal node will have the sum of both of its children
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // Helper function to get the sum in a range
    int query(int node, int start, int end, int L, int R) {
        // 1. Range represented by a node is completely outside the given range
        if (R < start || L > end) {
            return 0; 
        }
        
        // 2. Range represented by a node is completely inside the given range
        if (L <= start && end <= R) {
            return tree[node];
        }
        
        // 3. Range represented by a node is partially inside and partially outside the given range
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        int leftSum = query(leftChild, start, mid, L, R);
        int rightSum = query(rightChild, mid + 1, end, L, R);
        
        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            // Maximum size of segment tree is 4 * n
            tree.resize(4 * n, 0); 
            build(0, 0, n - 1, nums);
        }
    }
    
    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(0, 0, n - 1, left, right);
    }
};