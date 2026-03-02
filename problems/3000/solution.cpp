class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        sort(begin(d), end(d), [](const vector<int>& a, const vector<int>& b) {
            double d1 = sqrt(a.front() * a.front() + a.back() * a.back()),
                d2 = sqrt(b.front() * b.front() + b.back() * b.back());
            
            if (d1 == d2) {
                return a.front() * a.back() < b.front() * b.back();
            }

            return d1 < d2;
        });

        return d.back().front() * d.back().back();
    }
};