class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<int>> m;

        for (int i = 0; i < size(words); i++) {
            vector<int> v;

            for (int j = 1; j < size(words[i]); j++) {
                v.push_back(words[i][j] - words[i][j - 1]);
            }

            m[v].push_back(i);
        }

        for (auto& [_, ws]: m) {
            if (size(ws) == 1) {
                return words[ws.front()];
            }
        }

        return "";
    }
};