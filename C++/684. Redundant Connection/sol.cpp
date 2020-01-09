class DisjointSet {
private:
    vector<int> p;
    vector<int> rank;
    
public:
    DisjointSet(int size) {
        p = vector<int>(size, 0);
        rank = vector<int>(size, 0);
        for (int i = 0; i < size; i++) {
            p[i] = i;
        }
    }
    
    bool unionXY(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return false;
        }
        
        int rankx = rank[px], ranky = rank[py];
        if (rankx > ranky) {
            p[py] = px;
        }
        else if (rankx < ranky) {
            p[px] = py;
        }
        else {
            p[px] = py;
            rank[py]++;
        }
        return true;
    }
    
    int find(int x) {
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size() + 1);
        for (auto& edge : edges) {
            if (!ds.unionXY(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};