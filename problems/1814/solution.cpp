const int MOD = 1e9 + 7;

class Solution {
private:
    int rev(int num) {
        string snum = to_string(num);
        
        reverse(begin(snum), end(snum));
        
        return stoi(snum);
    }
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            int x = num - rev(num);
            ans = (ans + um[x]) % MOD;
            um[x]++;
        }
        
        return ans;
    }
};