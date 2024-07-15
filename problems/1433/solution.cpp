class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool a = true,
            b = true;
        
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        
        for (int i = 0; i < size(s1) and (a or b); i++) {
            if (s1[i] < s2[i]) {
                a = false;
            }
            
            if (s2[i] < s1[i]) {
                b = false;
            }
        }
        
        return a or b;
    }
};