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
    void postorderNary(Node* node, vector<int>& result) {
        if (!node)
            return;
        for (auto child : node->children)
            postorderNary(child, result);
        result.push_back(node->val);
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderNary(root, result);
        return result;
    }
};