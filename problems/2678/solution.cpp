class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(begin(details), end(details), [](const string& str) {
            int age = (str[11] - '0') * 10 + (str[12] - '0');
            
            return age > 60;
        });
    }
};