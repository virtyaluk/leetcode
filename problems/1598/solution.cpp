class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        
        for (const string& log: logs) {
            if (log == "../") {
                if (ans >= 1) {
                    ans--;
                }
            } else if (log != "./") {
                ans++;
            }
        }
        
        return ans;
    }
};