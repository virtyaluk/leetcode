class Solution {
public:
    int shortestWay(string source, string target) {
        int idx = 0, n = size(source), m = size(target), ans = 0;
        
        while (idx < m) {
            bool found = false;
            
            for (const char& ch: source) {
                if (ch == target[idx]) {
                    idx++;
                    found = true;
                }
            }
            
            if (found) {
                ans++;
            } else {
                return -1;
            }
        }
        
        return ans;
    }
};