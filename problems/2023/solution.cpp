class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        unordered_map<string, int> freq;
        
        for (string& num: nums) {
            if (size(num) < size(target)) {
                freq[num]++;
            }
        }
        
        for (auto& [num, fr]: freq) {
            if (target.find(num) == 0) {
                if (num + num == target) {
                    ans += fr * (fr - 1);
                } else {
                    ans += fr * freq[target.substr(size(num))];
                }
            }
        }
        
        return ans;
    }
};