class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        
        unordered_map<char, char> um;
        
        for(int i = 0; i < size(str1); i++) {
            if (um.count(str1[i]) and um[str1[i]] != str2[i]) {
                return false;
            }
            
            um[str1[i]] = str2[i];
        }
        
        return size(unordered_set(begin(str2), end(str2))) < 26;
    }
};