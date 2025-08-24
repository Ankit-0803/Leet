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
    // Hash map to store mapping from original -> cloned node
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;  // empty graph
        // If already cloned, return the clone
        if (mp.find(node) != mp.end())
            return mp[node];
        // Step 1: Create a new clone node
        Node* clone = new Node(node->val);
        mp[node] = clone;  // store in map
        // Step 2: Recursively clone all neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};
