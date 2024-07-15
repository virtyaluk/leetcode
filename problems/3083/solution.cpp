class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> us;
        
        for (int i = 1; i < size(s); i++) {
            string cur;
            
            cur.push_back(s[i - 1]);
            cur.push_back(s[i]);
            us.insert(cur);
        }
        
        reverse(begin(s), end(s));
        
        for (int i = 1; i < size(s); i++) {
            string cur;
            
            cur.push_back(s[i - 1]);
            cur.push_back(s[i]);
            
            if (us.count(cur)) {
                return true;
            }
        }
        
        return false;
    }
};