class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i = -1, j = -1;
        
        for (int k = 0; k < size(s1); k++) {
            if (s1[k] == s2[k]) {
                continue;
            }
            
            if (i == -1) {
                i = k;
            } else if (j == -1) {
                j = k;
                
                swap(s1[i], s1[j]);
                
                return s1 == s2;
            }
        }
        
        return i == j;
    }
};