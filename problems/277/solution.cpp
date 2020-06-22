/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // for (int i = 0; i < n; i++) {
        //     if (isCeleb(i, n)) {
        //         return i;
        //     }
        // }
        
        int cand = 0;
        
        for (int i = 1; i < n; i++) {
            if (knows(cand, i)) {
                cand = i;
            }
        }
        
        if (isCeleb(cand, n)) {
            return cand;
        }
        
        return -1;
    }
    
    bool isCeleb(int i, int n) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            
            if (knows(i, j) or not knows(j, i)) {
                return false;
            }
        }
        
        return true;
    }
};