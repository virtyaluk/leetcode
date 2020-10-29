class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        unordered_set<string> b(bank.begin(), bank.end()), visited = {start};
        unordered_set<char> abc = {'A', 'C', 'G', 'T'};
        queue<string> q;
        
        q.push(start);
        
        while (not empty(q)) {
            for (int i = size(q); i > 0; i--) {
                string gene = q.front();
                q.pop();
                
                if (gene == end) {
                    return ans;
                }
                
                for (char& ch: gene) {
                    char oldCh = ch;
                    
                    for (const char& cand: abc) {
                        if (ch == cand) {
                            continue;
                        }
                        
                        ch = cand;
                        
                        if (b.count(gene) and visited.insert(gene).second) {
                            q.push(gene);
                        }
                    }
                    
                    ch = oldCh;
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};