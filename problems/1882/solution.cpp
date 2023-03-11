class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> freeServers,
            taskQueue;
        vector<int> ans;
        
        for (int i = 0; i < size(servers); i++) {
            freeServers.push({servers[i], i});
        }
        
        for (int i = 0, time = 0; i < size(tasks); i++) {
            time = max(time, i);
            
            if (empty(freeServers)) {
                time = taskQueue.top()[0];
            }
            
            while (not empty(taskQueue) and taskQueue.top()[0] <= time) {
                freeServers.push({taskQueue.top()[1], taskQueue.top()[2]});
                taskQueue.pop();
            }
            
            auto free = freeServers.top();
            
            freeServers.pop();
            ans.push_back(free[1]);
            taskQueue.push({time + tasks[i], free[0], free[1]});
        }
        
        return ans;
    }
};