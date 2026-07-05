class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<int> vi;

        for (const int& num: nums) {
            um[num]++;
        }

        for (auto& [num, _]: um) {
            vi.push_back(num);
        }

        sort(begin(vi), end(vi));

        for (int i = 0; i < size(vi); i++) {
            for (int j = i + 1; j < size(vi); j++) {
                int x = vi[i],
                    y = vi[j];

                if (um[x] != um[y]) {
                    return {x, y};
                }
            }
        }

        return {-1, -1};
    }
};