class Solution {
public:
    bool canConstruct(string s, int k) {
        if (size(s) < k) {
            return false;
        }

        unordered_map<char, int> us;
        int odd = 0;

        for (const char& ch: s) {
            us[ch]++;
        }

        for (auto [_, cnt]: us) {
            odd += cnt % 2 == 1;
        }

        return odd <= k;
    }
};