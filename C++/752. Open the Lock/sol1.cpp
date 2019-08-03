class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int step = -1;
        queue<string> bfs;
        set<string> tried;
        string init = "0000";
        
        if (find(deadends.begin(), deadends.end(), init) != deadends.end())
            return -1;
        
        bfs.push(init);
        tried.insert(init);
        
        while (!bfs.empty()) {
            ++step;
            int size = bfs.size();
            for (int i = 0; i < size; ++i) {
                string wheels = bfs.front();
                if (wheels == target)                   // find the target
                    return step;
                else {      
                    for (int j = 0; j < 4; ++j) {
                        string up = wheels, down = wheels;
                        up[j] = (up[j] != '9' ? up[j] + 1 : '0');
                        down[j] = (down[j] != '0' ? down[j] - 1 : '9');
                        if (tried.find(up) == tried.end() && find(deadends.begin(), deadends.end(), up) == deadends.end()) {
                            bfs.push(up);
                            tried.insert(up);
                        }
                        if (tried.find(down) == tried.end() && find(deadends.begin(), deadends.end(), down) == deadends.end()) {
                            bfs.push(down);
                            tried.insert(down);
                        }
                    }
                }
                bfs.pop();
            }
        }
        
        return -1;
    }
};