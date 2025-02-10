class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(begin(nums), end(nums));
        unordered_map<int, int> um1;
        unordered_map<int, list<int>> um2;
        int group = 0;

        sort(begin(sorted), end(sorted));

        um1[sorted.front()] = group;
        um2[group] = {sorted.front()};

        for (int i = 1; i < size(nums); i++) {
            if (abs(sorted[i] - sorted[i - 1]) > limit) {
                group++;
            }

            um1[sorted[i]] = group;

            if (um2.find(group) == end(um2)) {
                um2[group] = {};
            }

            um2[group].push_back(sorted[i]);
        }

        for (int i = 0; i < size(nums); i++) {
            int g = um1[nums[i]];
            
            nums[i] = *begin(um2[g]);
            um2[g].pop_front();
        }

        return nums;
    }
};