class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        
        for (const string& pref: words) {
            ans += s.find(pref) == 0;
        }
        
        return ans;
    }
};