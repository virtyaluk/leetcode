class Solution {
private:
    string repeat(const string& input, unsigned num) {
        string ret;
        
        ret.reserve(input.size() * num);
        
        while (num--) {
            ret += input;
        }
    
        return ret;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string ans, pref;
        
        for (const char& ch: str1) {
            pref.push_back(ch);
            int len1 = size(str1) / size(pref),
                len2 = size(str2) / size(pref);
            
            if (repeat(pref, len1) == str1 and repeat(pref, len2) == str2) {
                ans = pref;
            }
        }
        
        return ans;
    }
};