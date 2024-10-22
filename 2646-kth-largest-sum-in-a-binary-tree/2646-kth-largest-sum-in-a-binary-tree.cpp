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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            long long levelSum = 0;
            

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            

            minHeap.push(levelSum);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        

        if (minHeap.size() < k) return -1;
        

        return minHeap.top();
    }



    // MYK
    // long long kthLargestLevelSum(TreeNode* root, int k) {
    //     vector<long long> sum_str;
    //     int level = 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int n = q.size();
    //         long long sum = 0;
    //         for(int i = 0; i<n; i++){
    //             TreeNode* temp = q.front();
    //             q.pop();
    //             sum += temp->val;
    //             if(temp->left) q.push(temp->left);
    //             if(temp->right) q.push(temp->right);
    //         }
    //         level++;
    //         if (sum_str.empty() || sum_str.back() != sum) {
    //             sum_str.push_back(sum);
    //         }
    //     }

    //     if(k > level) return -1;
    //     sort(sum_str.begin(), sum_str.end(), greater<long long>());
    //     return sum_str[k - 1];

    // }
};