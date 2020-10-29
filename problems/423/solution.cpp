class Solution {
public:
    string originalDigits(string s) {
        string ans;
        vector<int> digits(10), counter(26);
        
        for (const char& ch: s) {
            counter[ch - 'a']++;
        }
        
        digits[0] = counter['z' - 'a'];
        digits[2] = counter['w' - 'a'];
        digits[4] = counter['u' - 'a'];
        digits[6] = counter['x' - 'a'];
        digits[8] = counter['g' - 'a'];
        digits[3] = counter['h' - 'a'] - digits[8];
        digits[5] = counter['f' - 'a'] - digits[4];
        digits[7] = counter['s' - 'a'] - digits[6];
        digits[9] = counter['i' - 'a'] - digits[5] - digits[6] - digits[8];
        digits[1] = counter['n' - 'a'] - digits[7] - 2 * digits[9];
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++) {
                ans += to_string(i);
            }
        }
        
        return ans;
    }
};