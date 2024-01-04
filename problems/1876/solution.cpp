class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_set<char> us;
        int ans = 0;
        
        for (int i = 2; i < size(s); i++) {
            us.insert(s[i]);
            us.insert(s[i - 1]);
            us.insert(s[i - 2]);
            
            ans += size(us) == 3;
            
            us.clear();
        }
        
        return ans;
    }
};