class Solution {
private:
    vector<int> getIndegree(int numCourses, vector<vector<int>>& graph) {
        vector<int> indegree(numCourses, 0);
        for (auto v: graph) {
            for (int node : v) {
                indegree[node]++;
            }
        }
        return indegree;
    }
    
    vector<vector<int>> getAdjacents(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacents(numCourses);
        for (auto v : prerequisites) {
            adjacents[v[1]].push_back(v[0]);
        }
        return adjacents;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = getAdjacents(numCourses, prerequisites);
        vector<int> indegree = getIndegree(numCourses, graph);
        
        int coursesWith0Indegree = 0;
        while (coursesWith0Indegree < numCourses) {
            int i;
            for (i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    break;
                }
            }
            
            if (i == numCourses) {
                return false;
            }
            indegree[i]--;                  // set it to -1
            for (int adjacent : graph[i]) {
                indegree[adjacent]--;
            }
            coursesWith0Indegree++;
        }
        
        return true;
    }
};