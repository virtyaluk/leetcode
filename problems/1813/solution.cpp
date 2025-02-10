class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1),
            ss2(sentence2);
        string word;
        vector<string> s1, s2;
        int start = 0,
            s1e,
            s2e;
        
        while (ss1 >> word) {
            s1.push_back(word);
        }
        
        while (ss2 >> word) {
            s2.push_back(word);
        }
        
        s1e = size(s1) - 1;
        s2e = size(s2) - 1;
        
        if (size(s1) > size(s2)) {
            return areSentencesSimilar(sentence2, sentence1);
        }
        
        while (start < size(s1) and s1[start] == s2[start]) {
            start++;
        }
        
        while (s1e >= 0 and s1[s1e] == s2[s2e]) {
            s1e--;
            s2e--;
        }
        
        return s1e < start;
    }
};