class Solution {
public:
    int minimumLength(string s) {
        int ans = size(s);
        unordered_map<char, int> um;

        for (const char& ch: s) {
            um[ch]++;
        }

        for (auto [_, cnt]: um) {
            while (cnt > 2) {
                ans -= 2;
                cnt -= 2;
            }
        }

        return ans;
    }
};