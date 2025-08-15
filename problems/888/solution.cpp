class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int dif = (accumulate(begin(aliceSizes), end(aliceSizes), 0) - accumulate(begin(bobSizes), end(bobSizes), 0)) / 2;
        unordered_set<int> us(begin(aliceSizes), end(aliceSizes));

        for (const int& num: bobSizes) {
            if (us.count(num + dif)) {
                return {num + dif, num};
            }
        }

        return {};
    }
};