class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        unordered_map<char, int> um;
        
        for (int i = 0; i < size(s); i++) {
            um[s[i]] = i;
        }
        
        for (int i = 0; i < size(t); i++) {
            ans += abs(um[t[i]] - i);
        }
        
        return ans;
    }
};