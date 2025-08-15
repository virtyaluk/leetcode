class Solution {
public:
    bool isFascinating(int n) {
        vector<int> v{n, 2 * n, 3 * n};
        unordered_set<int> us;

        for (int m: v) {
            int d;

            while (m) {
                d = m % 10;
                m /= 10;

                if (not d or us.count(d)) {
                    return false;
                }
                
                us.insert(d);
            }
        }

        return size(us) == 9;
    }
};