class Solution {
public:
    int residuePrefixes(string s) {
        int ans = 0;
        unordered_set<char> us;

        for (int i = 0; i < size(s); i++) {
            us.insert(s[i]);
            ans += size(us) == (i + 1) % 3;
        }

        return ans;
    }
};