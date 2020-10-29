class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        
        q.push(kill);
        
        for (int i = 0; i < pid.size(); i++) {
            graph[ppid[i]].push_back(pid[i]);
        }
        
        while (not q.empty()) {
            ans.push_back(q.front());
            q.pop();
            
            for (const int& npid: graph[ans.back()]) {
                q.push(npid);
            }
        }
        
        return ans;
    }
};