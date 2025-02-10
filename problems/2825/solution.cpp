class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        
        for (int i = 0; i < size(str1); i++) {
            if (j < size(str2) and (str1[i] == str2[j] or (str1[i] - 'a' + 1) % 26 == (str2[j] - 'a'))) {
                j++;
            }
        }
        
        return j >= size(str2);
    }
};