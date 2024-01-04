class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        
        while (i < size(word) and word[i] != ch) {
            i++;
        }
        
        if (i < size(word)) {
            reverse(begin(word), begin(word) + i + 1);
        }
        
        return word;
    }
};