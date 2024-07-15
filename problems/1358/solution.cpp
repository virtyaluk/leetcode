class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> abc(3, 0);
        
        for (int i = 0, j = 0; i < size(s); i++) {
            abc[s[i] - 'a']++;
            
            while (abc[0] and abc[1] and abc[2]) {
                ans += size(s) - i;
                abc[s[j++] - 'a']--;
            }
        }
        
        return ans;
    }
};