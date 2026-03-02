const double EPS = 0.0001;

class Solution {
private:
    bool isValid(const vector<int>& nums) {
        double a = nums[0],
            b = nums[1],
            c = nums[2],
            d = nums[3];
        
        return isValid(a + b, c, d) or isValid(a - b, c, d) or isValid(a * b, c, d) or isValid(a / b, c, d) or
            isValid(a, b + c, d) or isValid(a, b - c, d) or isValid(a, b * c, d) or isValid(a, b / c, d) or
            isValid(a, b, c + d) or isValid(a, b, c - d) or isValid(a, b, c * d) or isValid(a, b, c / d);
    }

    bool isValid(const double a, const double b, const double c) {
        return isValid(a + b, c) or isValid(a - b, c) or isValid(a * b, c) or (b and isValid(a / b, c)) or isValid(a, b + c) or isValid(a, b - c) or isValid(a, b * c) or (c and isValid(a, b / c));
    }

    bool isValid(const double a, const double b) {
        return abs(a + b - 24.0) < EPS or abs(a - b - 24.0) < EPS or abs(a * b - 24.0) < EPS or (b and abs(a / b - 24.0) < EPS);
    }
public:
    bool judgePoint24(vector<int>& cards) {
        sort(begin(cards), end(cards));

        do {
            if (isValid(cards)) {
                return true;
            }
        } while (next_permutation(begin(cards), end(cards)));

        return false;
    }
};