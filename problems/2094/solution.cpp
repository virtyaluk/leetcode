class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> um;
        vector<int> ans;
        
        for (const int& num: digits) {
            um[num]++;
        }
        
        for (int i = 1; i < 10; i++) {
            if (not um[i]) {
                continue;
            }
            
            um[i]--;
            
            for (int j = 0; j < 10; j++) {
                if (not um[j]) {
                    continue;
                }
                
                um[j]--;
                
                for (int k = 0; k < 10; k += 2) {
                    if (not um[k]) {
                        continue;
                    }
                    
                    ans.push_back(i * 100 + j * 10 + k);
                }
                
                um[j]++;
            }
            
            um[i]++;
        }
        
        return ans;
    }
};