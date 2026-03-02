class TaskManager {
private:
    unordered_map<int, pair<int, int>> meta;
    unordered_map<int, unordered_map<int, unordered_set<int>>> tasks;
    multiset<pair<int, int>> q;
public:
    TaskManager(vector<vector<int>>& tt) {
        for (const vector<int>& t: tt) {
            int uid = t[0],
                tid = t[1],
                prio = t[2];

            tasks[uid][prio].insert(tid);
            meta[tid] = {uid, prio};
            q.insert({prio, tid});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks[userId][priority].insert(taskId);
        meta[taskId] = {userId, priority};
        q.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto& [uid, oldPrio] = meta[taskId];

        q.erase({oldPrio, taskId});
        q.insert({newPriority, taskId});
        tasks[uid][oldPrio].erase(taskId);
        tasks[uid][newPriority].insert(taskId);
        meta[taskId] = {uid, newPriority};

    }
    
    void rmv(int taskId) {
        auto& [uid, prio] = meta[taskId];

        q.erase({prio, taskId});
        tasks[uid][prio].erase(taskId);
        meta.erase(taskId);
    }
    
    int execTop() {
        if (empty(q)) {
            return -1;
        }

        auto [_, tid] = *prev(end(q));
        auto [uid, _] = meta[tid];

        rmv(tid);

        return uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */