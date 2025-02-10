class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        vector<int> v(32, -1);
        unordered_map<char, int> um;
        um['a'] = 1;
        um['e'] = 2;
        um['i'] = 4;
        um['o'] = 8;
        um['u'] = 16;
        
        for (int i = 0, cur = 0; i < size(s); i++) {
            cur ^= um[s[i]];
            
            if (v[cur] == -1 and cur != 0) {
                v[cur] = i;
            }
            
            ans = max(ans, i - v[cur]);
        }
        
        return ans;
    }
};