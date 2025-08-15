class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;

        for (const int& f: fruits) {
            int unset = 1;

            for (int i = 0; i < size(baskets); i++) {
                if (f <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }

            ans += unset;
        }

        return ans;
    }
};