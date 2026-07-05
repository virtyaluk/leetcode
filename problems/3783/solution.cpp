class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);

        reverse(begin(s), end(s));

        return abs(n - stoi(s));
    }
};