class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ans = 0, cur = 0, ones = count(begin(data), end(data), 1);
        
        for (int i = 0; i < data.size(); i++) {
            if (i < ones) {
                cur += data[i];
                ans = ones - cur;
            } else {
                cur += data[i];
                cur -= data[i - ones];
                ans = min(ans, ones - cur);
            }
        }
        
        return ans;
    }
    
    int minSwaps1(vector<int>& data) {
        int ans = 0, ones = count(begin(data), end(data), 1), curOnes = 0;
        
        for (int i = 0; i < ones; i++) {
            if (data[i] == 1) {
                curOnes++;
            }
        }
        
        ans = ones - curOnes;
        
        for (int i = ones; i < data.size(); i++) {
            if (data[i] == 1) {
                curOnes++;
            }
            
            if (data[i - ones] == 1) {
                curOnes--;
            }
            
            ans = min(ans, ones - curOnes);
        }
        
        return ans;
    }
};