class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> freq;
        
        for (const int& num: tasks) {
            freq[num]++;
        }
        
        for (auto [num, fr]: freq) {
            if (fr == 1) {
                return -1;
            } else if (fr % 3 == 0) {
                ans += fr / 3;
            } else {
                ans += fr / 3 + 1;
            }
        }
        
        return ans;
    }
};