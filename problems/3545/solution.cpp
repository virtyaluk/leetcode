class Solution {
public:
    int minDeletion(string s, int k) {
        int ans = 0;
        unordered_map<char, int> um;
        vector<pair<int, char>> vp;

        for (const char& ch: s) {
            um[ch]++;
        }

        for (auto [ch, cnt]: um) {
            vp.push_back({cnt, ch});
        }

        sort(begin(vp), end(vp));

        for (int i = 0; i < size(vp) and size(um) > k; i++) {
            auto [cnt, ch] = vp[i];
            ans += cnt;
            um.erase(ch);
        }

        return ans;
    }
};