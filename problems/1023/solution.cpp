class Solution {
private:
    bool check(const string& q, const string& pattern) {
        int i = 0;
            
        for (const char& ch: q) {
            if (i < size(pattern) && ch == pattern[i]) {
                i++;
            } else if (ch < 'a') {
                return false;
            }
        }
        
        return i == size(pattern);
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        
        for (const string& q: queries) {
            ans.push_back(check(q, pattern));
        }
        
        return ans;
    }
};