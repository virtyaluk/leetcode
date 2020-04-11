class Solution {
private:
    unordered_map<string, bool> um;
    
    bool isScrambled(const string s1, const string s2) {
        if (size(s1) != size(s2)) {
            return false;
        }
        
        string key = s1 + " " + s2;
        int n = size(s1);
        
        if (s1 == s2 or not n) {
            return true;
        }
        
        if (um.count(key)) {
            return um[key];
        }
        
        bool flag = false;
        
        for (int i = 1; i < n; i++) {
            if (isScrambled(s1.substr(0, i), s2.substr(n - i, i)) and isScrambled(s1.substr(i, n - i), s2.substr(0, n - i))) {
                flag |= true;
                break;
            }
            
            if (isScrambled(s1.substr(0, i), s2.substr(0, i)) and isScrambled(s1.substr(i, n - i), s2.substr(i, n - i))) {
                flag |= true;
                break;
            }
        }
        
        return um[key] = flag;
    }
public:
    bool isScramble(string s1, string s2) {
        if (size(s1) != size(s2)) {
            return false;
        }
        
        return isScrambled(s1, s2);
    }
};