class Solution {
public:
    bool canPermutePalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> m;
        
        for (char& ch: s) {
            m[ch]++;
        }
        
        for (auto [_, freq]: m) {
            ans += freq % 2;
        }
        
        return ans <= 1;
    }
};