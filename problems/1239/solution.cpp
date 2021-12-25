class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0, n = size(arr);
        function<void(int, int, int)> backtrack;
        
        backtrack = [&](int idx, int cur, int len) {
            if (idx >= n) {
                ans = max(ans, len);
                return;
            }
            
            int code = getCode(arr[idx]);
            
            if (code != -1 and (cur & code) == 0) {
                backtrack(idx + 1, cur | code, len + size(arr[idx]));
            }
            
            backtrack(idx + 1, cur, len);
        };
        
        backtrack(0, 0, 0);
        
        return ans;
    }
    
    int getCode(const string& word) {
        int code = 0;
        
        for (const char& ch: word) {
            if (code & (1 << (ch - 'a'))) {
                return -1;
            }
            
            code |= (1 << (ch - 'a'));
        }
        
        return code;
    }
};