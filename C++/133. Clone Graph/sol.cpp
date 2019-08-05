/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> hashmap;
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        if (hashmap.find(node) == hashmap.end()) {
            hashmap[node] = new Node(node->val, {});
            for (Node* neighbor : node->neighbors)
                hashmap[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return hashmap[node];
    }
};