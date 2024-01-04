class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<int, int> um;
        
        for (int i = 0; i < size(s); i++) {
            if (um.count(s[i])) {
                ans = max(ans, i - um[s[i]] - 1);
            } else {
                um[s[i]] = i;
            }
        }
        
        return ans;
    }
};