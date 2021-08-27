class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = size(logs), lo = 0;
        vector<string> ans(n);
        
        for (int i = n - 1, hi = n - 1; i >= 0; i--) {
            if (isdigit(logs[i].back())) {
                ans[hi--] = logs[i];
            } else {
                ans[lo++] = logs[i];
            }
        }
        
        sort(begin(ans), begin(ans) + lo, [](const string& a, const string& b) {
            int ai = a.find(' '), bi = b.find(' ');
            string as = a.substr(ai), bs = b.substr(bi);
            
            if (as == bs) {
                return a.substr(0, ai) < b.substr(0, bi);
            }
            
            return as < bs;
        });
        
        return ans;
    }
};