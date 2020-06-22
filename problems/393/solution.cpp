class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numBytesLeft = 0,
            mask1 = 1 << 7,
            mask2 = 1 << 6;
        
        for (int i = 0; i < size(data); i++) {
            if (not numBytesLeft) {
                int mask = 1 << 7;
                
                while ((mask & data[i])) {
                    numBytesLeft++;
                    mask >>= 1;
                }
                
                if (not numBytesLeft) {
                    continue;
                }
                
                if (numBytesLeft > 4 or numBytesLeft == 1) {
                    return false;
                }
            } else {
                if (not ((data[i] & mask1) and not (mask2 & data[i]))) {
                    return false;
                }
            }
            
            numBytesLeft--;
        }
        
        return not numBytesLeft;
    }
};