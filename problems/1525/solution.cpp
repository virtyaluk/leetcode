class Solution {
public:
    int numSplits(string s) {
        int ans = 0, n = size(s);
        unordered_map<char, int> left, right;
        
        for (const char& ch: s) {
            right[ch]++;
        }
        
        for (int i = 0; i < n - 1; i++) {
            left[s[i]]++;
            right[s[i]]--;
            
            if (right[s[i]] == 0) {
                right.erase(s[i]);
            }
            
            if (size(left) == size(right)) {
                ans++;
            }
        }
        
        return ans;
    }
};