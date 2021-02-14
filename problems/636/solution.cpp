struct Log {
    int id, time;
    string func;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<Log> st;
        
        for (const string& log: logs) {
            istringstream iss(log);
            string id, func, time;
            
            getline(iss, id, ':');
            getline(iss, func, ':');
            getline(iss, time, ':');
            
            Log item = {stoi(id), stoi(time), func};
            
            if (func == "start") {
                st.push(item);
            } else {
                int elapsed = item.time - st.top().time + 1;
                st.pop();
                
                ans[item.id] += elapsed;
                
                if (not empty(st)) {
                    ans[st.top().id] -= elapsed;
                }
            }
        }
        
        return ans;
    }
};