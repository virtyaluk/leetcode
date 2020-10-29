class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) {
            reverse(s, i, min(i + k - 1, s.size() - 1));
        }
        
        return s;
    }
    
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};