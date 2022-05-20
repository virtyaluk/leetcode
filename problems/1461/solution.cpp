class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        } 
        
        unordered_set<string> us;
        
        for (int i = 0; i < s.size() - k + 1; i++) {
            us.insert(s.substr(i, k));
        }
        
        // for (int i = (1 << k) - 1; i >= 0; i--) {
        //     if (us.find(bitset<32>(i).to_string().substr(32 - k)) == us.end()) {
        //         return false;
        //     }
        // }
        
        return us.size() == pow(2, k);
    }
};