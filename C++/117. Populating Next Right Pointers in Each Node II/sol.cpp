/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<Node*> level;
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                level.push_back(node);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            for (int j = 0; j < level.size() - 1; ++j)
                level[j]->next = level[j+1];
        }
        return root;
    }
};