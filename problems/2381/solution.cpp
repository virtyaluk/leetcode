class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> um;

        for (const vector<int>& s: shifts) {
            int start = s[0],
                end = s[1],
                dir = s[2];

            if (dir == 1) {
                um[start]++;
                um[end + 1]--;
            } else {
                um[start]--;
                um[end + 1]++;
            }
        }

        for (int i = 0, cur = 0; i < size(s); i++) {
            cur = (cur + um[i]) % 26;

            if (cur < 0) {
                cur += 26;
            }

            s[i] = 'a' + (s[i] - 'a' + cur) % 26;
        }

        return s;
    }
};