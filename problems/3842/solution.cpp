class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int> m;
        vector<int> ans;

        for (const int& b: bulbs) {
            m[b]++;
        }

        for (auto& [b, freq]: m) {
            if (freq % 2 != 0) {
                ans.push_back(b);
            }
        }

        return ans;
    }
};