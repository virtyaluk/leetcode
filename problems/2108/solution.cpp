class Solution {
private:
    bool isPalindrome(const string& word) {
        int lo = 0, hi = size(word) - 1;
        
        while (lo <= hi) {
            if (word[lo++] != word[hi--]) {
                return false;
            }
        }
        
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word: words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        
        return "";
    }
};