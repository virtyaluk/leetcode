class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sn = size(s), pn = size(p);
        vector<int> ans, pfreq(26), sfreq(26);
        
        for (const char& ch: p) {
            pfreq[ch - 'a']++;
        }
        
        for (int i = 0; i < sn; i++) {
            sfreq[s[i] - 'a']++;
            
            if (i >= pn) {
                sfreq[s[i - pn] - 'a']--;
            }
            
            if (pfreq == sfreq) {
                ans.push_back(i - pn + 1);
            }
        }
        
        return ans;
    }
};