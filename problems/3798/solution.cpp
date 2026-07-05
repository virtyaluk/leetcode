class Solution {
public:
    string largestEven(string s) {
        return s.substr(0, s.find_last_of('2') + 1);
    }
};