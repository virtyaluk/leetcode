class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> us = {begin(sentence), end(sentence)};
        
        return size(us) == 26;
    }
};