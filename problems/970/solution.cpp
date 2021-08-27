class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int maxI = x == 1 ? bound : log(bound) / log(x),
            maxJ = y == 1 ? bound : log(bound) / log(y);
        vector<int> ans;
        unordered_set<int> us;
        
        for (int i = 0; i <= maxI; i++) {
            for (int j = 0; j <= maxJ; j++) {
                int pi = pow(x, i) + pow(y, j);
                
                if (pi <= bound) {
                    us.insert(pi);
                }
                
                if (y == 1) {
                    break;
                }
            }
            
            if (x == 1) {
                break;
            }
        }
        
        for (const int& pi: us) {
            ans.push_back(pi);
        }
        
        return ans;
    }
};