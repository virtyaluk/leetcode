class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0, right = 0, n = size(s);
        unordered_set<char> us;
        
        while (right < n) {
            if (not us.count(s[right])) {
                us.insert(s[right++]);
                ans = max(ans, right - left);
            } else {
                us.erase(s[left++]);
            }
        }
        
        return ans;
    }
};