class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int m = mass;

        sort(begin(asteroids), end(asteroids));

        for (const int& a: asteroids) {
            if (a > m) {
                return false;
            }

            m += a;
        }

        return true;
    }
};