class Solution {
public:
    char findKthBit(int n, int k) {
        int posInSection = k & -k;
        bool isInInvertedPart = ((k / posInSection) >> 1 & 1) == 1,
            origBitIs1 = (k & 1) == 0;
        
        if (isInInvertedPart) {
            return origBitIs1 ? '0' : '1';
        }
        
        return origBitIs1 ? '1' : '0';
    }
};