/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> mpp;
        queue<Node*> q;
        q.push(node);
        mpp[node] = new Node(node->val);
        while(!q.empty()) {
            Node* temp = q.front(); q.pop();

            for(auto it:temp->neighbors) {
                if(!mpp.count(it)){
                    mpp[it] = new Node(it->val);
                    q.push(it);
                }
                mpp[temp]->neighbors.push_back(mpp[it]);
            }
        }
        return mpp[node];
    }
};