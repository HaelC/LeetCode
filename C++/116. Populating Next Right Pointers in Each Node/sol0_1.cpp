/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            Node* lastNode = nullptr;
            for (int i = 0; i < size; i++) {
                Node* node = bfs.front();
                bfs.pop();
                if (lastNode) {
                    lastNode->next = node;
                }
                lastNode = node;
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
            }
        }
        return root;
    }
};