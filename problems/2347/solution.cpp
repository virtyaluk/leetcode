class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> um1,
            um2;
        int maxCount = 0;

        for (const char& ch: suits) {
            um1[ch]++;
        }

        for (const int& num: ranks) {
            maxCount = max(maxCount, ++um2[num]);
        }

        if (size(um1) == 1) {
            return "Flush";
        }

        if (maxCount >= 3) {
            return "Three of a Kind";
        }

        if (maxCount == 2) {
            return "Pair";
        }

        return "High Card";
    }
};