class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto letterVal = [](const string& word) {
            return accumulate(begin(word), end(word), 0, [](int val, char ch) {
                return val * 10 + (ch - 'a');
            });
        };
        
        return letterVal(firstWord) + letterVal(secondWord) == letterVal(targetWord);
    }
};