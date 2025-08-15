class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string ans;
        unordered_map<string, int> um;
        int maxFreq = 0;

        for (const vector<string>& r: responses) {
            unordered_set<string> us(begin(r), end(r));

            for (const string& s: us) {
                um[s]++;
                maxFreq = max(maxFreq, um[s]);
            }
        }

        for (auto [w, freq]: um) {
            if (freq == maxFreq and (empty(ans) or w < ans)) {
                ans = w;
            }
        }

        return ans;
    }
};