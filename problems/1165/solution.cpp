class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int ans = 0, lastPos = 0;
        vector<int> positions(26);
        
        for (int i = 0; i < keyboard.size(); i++) {
            positions[keyboard[i] - 'a'] = i;
        }
        
        for (const char& ch: word) {
            ans += abs(lastPos - positions[ch - 'a']);
            lastPos = positions[ch - 'a'];
        }
        
        return ans;
    }
};