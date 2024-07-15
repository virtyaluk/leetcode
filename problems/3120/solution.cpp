class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_set<char> us(begin(word), end(word));
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (us.count(ch) and us.count(toupper(ch))) {
                ans++;
            }
        }
        
        return ans;
    }
};