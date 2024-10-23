/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int finder(vector<int>& arr, int low , int high){
        int maxi = low;
        for(int i = low; i <= high; i++){
            if(arr[maxi] < arr[i]) maxi = i;
        }
        return maxi;
    }

    TreeNode* helper(vector<int>& arr, int low, int high){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (low > high) return nullptr;  // Base case: when the range is invalid
        
        int divide = finder(arr, low, high);
        TreeNode* root = new TreeNode(arr[divide]);

        // Recursively construct the left and right subtrees
        root->left = helper(arr, low, divide - 1);
        root->right = helper(arr, divide + 1, high);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};