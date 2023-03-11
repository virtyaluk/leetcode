class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        vector<int> abc(26, -1);
        
        for (int i = 0, j = 0; i < size(s); i++) {
            if (abc[s[i] - 'a'] >= j) {
                ans++;
                j = i;
            }
            
            abc[s[i] - 'a'] = i;
        }
        
        return ans;
    }
};