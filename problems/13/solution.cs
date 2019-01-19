public class Solution {
    public int RomanToInt(string s) {
        var mapping = new Dictionary<char, int> {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        var sum = 0;
        
        for (var i = 0; i < s.Length; i++) {
            if (i != 0 && mapping[s[i - 1]] < mapping[s[i]]) {
                sum -= 2 * mapping[s[i - 1]];
            }
            
            sum += mapping[s[i]];
        }
        
        return sum;
    }
}