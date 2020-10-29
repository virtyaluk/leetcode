class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        
        while (i < size(word) and j < size(abbr)) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
            } else {
                int num = 0;
                
                if (isdigit(abbr[j])) {
                    if (abbr[j] == '0') {
                        return false;
                    }
                    
                    while (j < size(abbr) and isdigit(abbr[j])) {
                        num = num * 10 + (abbr[j++] - '0');
                    }
                } else {
                    return false;
                }
                
                i += num;
            }
        }
        
        return i == size(word) and j == size(abbr);
    }
};