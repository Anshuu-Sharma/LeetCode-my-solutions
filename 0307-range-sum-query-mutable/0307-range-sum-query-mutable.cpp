class NumArray {
private:
    vector<int> tree;
    int n;

    void build(int node, int start, int end, vector<int>& nums){
        if(start == end){
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start)/2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(leftChild, start, mid, nums);
        build(rightChild, mid+1, end, nums);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    int query(int node, int start, int end, int l, int r){
        if (r < start || l > end) {
            return 0; 
        }

        if(l <= start && end <= r){
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        int leftSum = query(leftChild, start, mid, l, r);
        int rightSum = query(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    void updateValue(int idx, int index, int val, int start, int end){
        if(start == end){
            tree[index] = val;
            return;
        }

        int mid = start + (end-start)/2;

        if(idx<=mid){
            updateValue(idx, 2*index+1, val, start, mid);
        }
        else{
            updateValue(idx, 2*index+2, val, mid+1, end);
        }

        tree[index] = tree[2*index+1] + tree[2*index+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n > 0){
            tree.resize(4 * n, 0); 
            build(0, 0, n - 1, nums);
        }
    }
    
    void update(int index, int val) {
        updateValue(index, 0, val, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */