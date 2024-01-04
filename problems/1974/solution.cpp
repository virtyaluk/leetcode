class Solution {
public:
    int minTimeToType(string word) {
        int ans = size(word);
        char lastKey = 'a';
        
        for (const char& ch: word) {
            ans += min(
                abs(ch - lastKey),
                26 - abs(lastKey - ch)
            );
            lastKey = ch;
        }
        
        return ans;
    }
};