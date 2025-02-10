class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        vector<vector<int>> v(26, vector<int>(52, 0));
        
        for (int i = 0, cnt = 0; i < size(s); i++) {
            if (i > 0 and s[i] == s[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            
            v[s[i] - 'a'][1]++;
            v[s[i] - 'a'][cnt + 1]--;
        }
        
        for (const vector<int>& line: v) {
            for (int i = 1, cur = 0; i < size(line); i++) {
                cur += line[i];
                
                if (cur >= 3) {
                    ans = max(ans, i);
                }
            }
        }
        
        return ans;
    }
};