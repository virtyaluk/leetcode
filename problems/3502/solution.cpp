class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        partial_sum(begin(cost), end(cost), begin(cost), [](const int& a, const int& b) { return min(a, b);});

        return cost;
    }
};