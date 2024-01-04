const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        return count_if(begin(words) + left, begin(words) + right + 1, [&](const string& word) {
            return vowels.count(word.front()) and vowels.count(word.back());
        });
    }
};