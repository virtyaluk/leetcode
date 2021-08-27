class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> abc;
        
        for (int i = 0; i < size(order); i++) {
            abc[order[i]] = i;
        }
        
        for (int i = 0; i < size(words) - 1; i++) {
            if (not checkWords(abc, words[i], words[i + 1])) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkWords(unordered_map<char, int>& abc, string& prev, string& cur) {
        int m = size(prev), n = size(cur);
        
        for (int i = 0; i < m and i < n; i++) {
            if (abc[prev[i]] != abc[cur[i]]) {
                return abc[cur[i]] > abc[prev[i]];
            }
        }
        
        return n >= m;
    }
};