/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string using preorder traversal.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string result = to_string(root->val);
        if (root->left) {
            result += "," + serialize(root->left);
        }
        if (root->right) {
            result += "," + serialize(root->right);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string item;
        vector<int> vals;
        // to make vector of items
        while (getline(ss, item, ',')) {
            vals.push_back(stoi(item));
        }
        
        int index = 0;
        return buildBST(vals, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode* buildBST(const vector<int>& vals, int& index, int minVal, int maxVal) {
        if (index >= vals.size()) return nullptr;
        
        int val = vals[index];
        if (val < minVal || val > maxVal) return nullptr;
        
        index++;
        TreeNode* root = new TreeNode(val);
        root->left = buildBST(vals, index, minVal, val);
        root->right = buildBST(vals, index, val, maxVal);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;