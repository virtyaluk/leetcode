class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = size(baskets),
            m = sqrt(n),
            section = (n + m - 1) / m,
            ans = 0;
        vector<int> vi(section);

        for (int i = 0; i < n; i++) {
            vi[i / m] = max(vi[i / m], baskets[i]);
        }

        for (const int& f: fruits) {
            int sec,
                unset = 1;
            
            for (sec = 0; sec < section; sec++) {
                if (vi[sec] < f) {
                    continue;
                }

                int choose = 0;
                vi[sec] = 0;

                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;

                    if (pos < n and baskets[pos] >= f and not choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }

                    if (pos < n) {
                        vi[sec] = max(vi[sec], baskets[pos]);
                    }
                }

                unset = 0;
                break;
            }

            ans += unset;
        }

        return ans;
    }
};