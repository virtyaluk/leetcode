class Solution {
public:
    bool isValid(string word) {
        if (size(word) < 3) {
            return false;
        }

        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool hasVowels = false,
            hasCons = false;
        
        for (const char& ch: word) {
            if (not isalnum(ch)) {
                return false;
            }

            if (isalpha(ch)) {
                if (vowels.count(ch)) {
                    hasVowels = true;
                } else {
                    hasCons = true;
                }
            }
        }
        
        return hasVowels and hasCons;
    }
};