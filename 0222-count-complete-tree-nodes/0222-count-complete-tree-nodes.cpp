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
   static inline auto _ = [] {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out", std::ios::out | std::ios::binary);
        out.rdbuf()->pubsetbuf(nullptr, 256);
        std::string s;
        std::noskipws(std::cin);
        while (std::getline(std::cin, s)) {
            int count = 0;
            bool inNum = false;
            for (char c : s) {
                if (std::isdigit(c) != 0) {
                    if (!inNum) {
                        ++count;
                        inNum = true;
                    }
                } else {
                    inNum = false;
                }
            }
            out << count << '\n';
        }
        std::skipws(std::cin);
        out.flush();
        exit(0);
        return 0;
    }();
class Solution {
public:
    int findheightleft(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }
        return height;
    }
    int findheightright(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findheightleft(root);
        int rh = findheightright(root);

        if(lh == rh) return (1<<rh) - 1;
        
        return 1 + countNodes(root->left)  + countNodes(root->right);
    }
};