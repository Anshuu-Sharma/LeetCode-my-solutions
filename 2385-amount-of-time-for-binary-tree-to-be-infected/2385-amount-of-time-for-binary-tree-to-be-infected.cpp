class Solution {
    unordered_map<int, vector<int>> adj;
    
public:
    int amountOfTime(TreeNode* root, int start) {
        // Step 1: Build the adjacency list using DFS
        buildGraph(root, nullptr);
        
        // Step 2: Find max distance from the 'start' node using DFS
        // We pass 0 as the initial 'parent' since node values are >= 1
        return dfsInfection(start, 0); 
    }
    
private:
    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        // Connect current node and parent in both directions
        if (parent) {
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }
        
        // Traverse left and right children
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }
    
    int dfsInfection(int node, int parent) {
        int maxDistance = 0;
        
        // Explore all adjacent nodes
        for (int neighbor : adj[node]) {
            // Avoid going back to the node we just came from
            if (neighbor != parent) {
                maxDistance = max(maxDistance, 1 + dfsInfection(neighbor, node));
            }
        }
        
        return maxDistance;
    }
};