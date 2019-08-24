/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    int depth = 0;
    void findDepth(Node* node, int currentDepth, int &depth) {
        if (!node) return;
        
        if (currentDepth > depth)
            depth = currentDepth;
        
        for (auto child : node->children) {
            
            findDepth(child, currentDepth+1, depth);
        }
    }
    
    
public:
    int maxDepth(Node* root) {
        findDepth(root, 1, depth);
        return depth;
    }
};