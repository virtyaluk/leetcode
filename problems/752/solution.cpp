class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen(begin(deadends), end(deadends));
        queue<string> q;
        int ans = 0;
        
        q.push("0000");
        
        while (not q.empty()) {
            for (int l = q.size(); l > 0; l--) {
                string lock = q.front();
                q.pop();

                if (lock == target) {
                    return ans;
                }

                if (seen.count(lock)) {
                    continue;
                }

                seen.insert(lock);

                for (int i = 0; i < 4; i++) {
                    int slot = lock[i] - '0';
                    char dec = '0' + ((slot + 10 + 1) % 10),
                        inc = '0' + ((slot + 10 - 1) % 10);
                    
                    q.push(lock.substr(0, i) + dec + lock.substr(i + 1));
                    q.push(lock.substr(0, i) + inc + lock.substr(i + 1));
                }
            }
            
            
            ans++;
        }
        
        return -1;
    }
};