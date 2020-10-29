class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = size(matchsticks), sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        
        if (sum % 4 != 0) {
            return false;
        }
        
        int all = (1 << n) - 1,
            sideSum = sum / 4;
        vector<int> masksSeen;
        vector<bool> halfMasks(1 << n);
        
        for (int mask = 0; mask <= all; mask++) {
            int subsetSum = 0;
            
            for (int i = 0; i < size(matchsticks); i++) {
                if ((mask & (1 << i)) != 0) {
                    subsetSum += matchsticks[i];
                }
            }
            
            if (subsetSum == sideSum) {
                for (const int& prevMask: masksSeen) {
                    if ((mask & prevMask) == 0) {
                        int halfMask = mask | prevMask;
                        halfMasks[halfMask] = true;
                        
                        if (halfMasks[all ^ halfMask]) {
                            return true;
                        }
                    }
                }
                
                masksSeen.push_back(mask);
            }
        }
        
        return false;
    }
};