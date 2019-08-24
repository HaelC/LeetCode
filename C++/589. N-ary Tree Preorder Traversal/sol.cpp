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
    void preorderNary(Node* node, vector<int>& result) {
        if (!node) {
            return;
        }
        result.push_back(node->val);
        for (auto child: node->children) {
            preorderNary(child, result);
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderNary(root, result);
        return result;
    }
};