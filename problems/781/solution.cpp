class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> um;

        for (const int& num: answers) {
            um[num]++;
        }

        for (auto& [num, cnt]: um) {
            ans += (num + 1) * ((cnt + num) / (num + 1));
        }

        return ans;
    }
};