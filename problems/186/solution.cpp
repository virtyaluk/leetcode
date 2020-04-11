class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(begin(s), end(s));
        
        for (int left = 0, right = 0; right <= size(s); right++) {
            if (right == size(s) or s[right] == ' ') {
                reverse(begin(s) + left, begin(s) + right);
                
                left = right + 1;
            }
        }
    }
};