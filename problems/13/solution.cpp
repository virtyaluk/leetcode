class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> um = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        for (int i = 0; i < size(s); i++) {
            int num1 = um[s[i]], num2 = 0;
            
            if (i + 1) {
                num2 = um[s[i + 1]];
            }
            
            if (num1 < num2) {
                ans -= num1;
            } else {
                ans += num1;
            }
        }
        
        return ans;
    }
};