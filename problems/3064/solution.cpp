/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        bitset<32> ans;
        
        for (int i = 0; i < 32; i++) {
            if (commonSetBits(1 << i) == 1) {
                ans[i] = true;
            }
        }
        
        return ans.to_ulong();
    }
};