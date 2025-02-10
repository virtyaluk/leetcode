class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> us;
        string str;
        
        for (int i = 0; i < size(word); i++) {
            if (word[i] >= '0' and word[i] <= '9') {
                while (i < size(word) and word[i] >= '0' and word[i] <= '9') {
                    str.push_back(word[i++]);
                }
                
                int j = 0;
                
                while (str[j] == '0') {
                    j++;
                }
                
                str.erase(begin(str), begin(str) + j);
                us.insert(str);
                
                str.clear();
            }
        }
        
        return size(us);
    }
};