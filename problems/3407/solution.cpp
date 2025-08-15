class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find("*");
        string b = p.substr(0, x),
            e = p.substr(x + 1);
        int i = s.find(b),
            j = s.rfind(e);
        
        return i != -1 and j != -1 and i + size(b) <= j;
    }
};