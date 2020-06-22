class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, unordered_set<int>> g;
        queue<int> q;
        int total = 0;
        
        for (const vector<int>& preq: prerequisites) {
            g[preq[1]].insert(preq[0]);
            indegree[preq[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (not empty(q)) {
            int course = q.front();
            q.pop();
            
            total++;
            
            for (const int& next: g[course]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return total == numCourses;
    }
};