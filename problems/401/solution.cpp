class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int i = 0; i < 1024; i++) {
            int h = i >> 6,
                m = i & 63;
            
            if (h < 12 and m < 60 and __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }

        return ans;
    }
};