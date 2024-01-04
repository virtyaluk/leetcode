class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> um;
        
        for (int i = 0; i < size(s); i++) {
            if (not um.count(s[i])) {
                um[s[i]] = i;
            } else if (i - um[s[i]] - 1 != distance[s[i] - 'a']) {
                return false;
            }
        }
        
        return true;
    }
};