class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2;
        unordered_map<int, char> um;

        for (const vector<int>& r: reservedSeats) {
            if (r[1] > 1 and r[1] < 10) {
                um[r.front()] |= 1 << (r[1] - 2);
            }
        }

        for (auto [row, seats]: um) {
            bool left = seats & 0b11110000,
                mid = seats & 0b00111100,
                right = seats & 0b00001111;
            ans -= left and mid and right ? 2 : 1;
        }

        return ans;
    }
};