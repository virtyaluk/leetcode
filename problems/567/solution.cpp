class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (size(s2) < size(s1)) {
            return false;
        }
        
        int n = size(s1);
        vector<int> s1freq(26), s2freq(26);
        
        for (int i = 0; i < n; i++) {
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        }
        
        if (s1freq == s2freq) {
            return true;
        }
        
        for (int i = n; i < size(s2); i++) {
            s2freq[s2[i] - 'a']++;
            s2freq[s2[i - n] - 'a']--;
            
            if (s1freq == s2freq) {
                return true;
            }
        }
        
        return false;
    }
};