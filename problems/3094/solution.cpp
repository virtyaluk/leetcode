/** 
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int ans = 0,
            cnt = commonBits(0);
        
        for (int i = 0; i < 32; i++) {
            if (commonBits(1 << i) > cnt) {
                ans |= 1 << i;
            }
            
            commonBits(1 << i);
        }
        
        return ans;
    }
};