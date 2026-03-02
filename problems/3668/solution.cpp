class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> um;

        for (int i = 0; i < size(order); i++) {
            um[order[i]] = i;
        }

        sort(begin(friends), end(friends), [&](const int& lhs, const int& rhs) {
            return um[lhs] < um[rhs];
        });

        return friends;
    }
};