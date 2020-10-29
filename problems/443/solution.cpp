class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        
        for (int i = 1, count = 1; i <= size(chars); i++) {
            if (i == size(chars) or chars[i] != chars[i - 1]) {
                chars[j++] = chars[i - 1];
                
                for (const char& ch: count > 1 ? to_string(count) : "") {
                    chars[j++] = ch;
                }
                
                count = 1;
            } else {
                count++;
            }
        }
        
        return j;
    }
};