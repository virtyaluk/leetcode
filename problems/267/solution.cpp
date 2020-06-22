class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        unordered_map<char, int> freq;
        int count = 0, chars = 0;
        char singleChar = '@';
        string perm;
        
        for (const char& ch: s) {
            freq[ch]++;
        }
        
        for (auto [ch, fr]: freq) {
            count += fr % 2;
            
            if (fr % 2) {
                singleChar = ch;
            }
        }
        
        if (count > 1) {
            return ans;
        }
        
        if (freq.count(singleChar) and freq[singleChar] != 1) {
            freq[singleChar]--;
        } else {
            freq.erase(singleChar);
        }
        
        backtrack(freq, singleChar, size(s), ans, perm);
        
        return ans;
    }
    
    void backtrack(
        unordered_map<char, int>& freq,
        char& singleChar,
        int chars,
        vector<string>& ans,
        string& perm
    ) {
        if (chars <= 1) {
            string rev(perm);
            
            reverse(begin(rev), end(rev));
            
            ans.push_back(perm);
            
            if (singleChar != '@') {
                ans.back().push_back(singleChar);
            }
            
            ans.back() += rev;
            
            return;
        }
        
        for (auto [ch, fr]: freq) {
            if (not fr) {
                continue;
            }
            
            perm.push_back(ch);
            freq[ch] -= 2;
            
            backtrack(freq, singleChar, chars - 2, ans, perm);
            
            perm.pop_back();
            freq[ch] += 2;
        }
    }
};