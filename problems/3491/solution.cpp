class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(begin(numbers), end(numbers));

        for (int i = 1; i < size(numbers); i++) {
            if (numbers[i].starts_with(numbers[i - 1])) {
                return false;
            }
        }

        return true;
    }
};