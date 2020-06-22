class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s, t) and helper(t, s);
    }
    
    bool helper(const string& s, const string& t) {
        unordered_map<char, char> abc;
        
        for (int i = 0; i < size(s); i++) {
            char ch1 = s[i], ch2 = t[i];
            
            if (abc.count(ch1)) {
                if (abc[ch1] != ch2) {
                    return false;
                }
            } else {
                abc[ch1] = ch2;
            }
        }
        
        return true;
    }
};