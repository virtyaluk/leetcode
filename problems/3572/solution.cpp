class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> xToMaxY;

        for (int i = 0; i < x.size(); ++i) {
            xToMaxY[x[i]] = max(xToMaxY[x[i]], y[i]);
        }

        if (xToMaxY.size() < 3) return -1;

        vector<int> maxYValues;
        for (const auto& entry : xToMaxY) {
            maxYValues.push_back(entry.second);
        }

        nth_element(maxYValues.begin(), maxYValues.end() - 3, maxYValues.end());
        int sum = 0;
        for (int i = maxYValues.size() - 3; i < maxYValues.size(); ++i) {
            sum += maxYValues[i];
        }

        return sum;
    }
};