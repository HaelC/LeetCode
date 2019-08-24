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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                Node* node = bfs.front();
                bfs.pop();
                level.push_back(node->val);
                for (auto child : node->children)
                    bfs.push(child);
            }
            result.push_back(level);
        }
        return result;
    }
};