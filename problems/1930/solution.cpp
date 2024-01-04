class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26, INT_MAX),
            right(26);
        int ans = 0;
        
        for (int i = 0; i < size(s); i++) {
            int si = s[i] - 'a';
            left[si] = min(left[si], i);
            right[si] = i;
        }
        
        for (int i = 0; i < 26; i++) {
            if (left[i] < right[i]) {
                ans += size(unordered_set<char>(begin(s) + left[i] + 1, begin(s) + right[i]));
            }
        }
        
        return ans;
    }
};