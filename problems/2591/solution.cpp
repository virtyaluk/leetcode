class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;

        if (money < 0) {
            return -1;
        }

        if (money / 7 == children and money % 7 == 0) {
            return children;
        }

        if (money / 7 == children - 1 and money % 7 == 3) {
            return children - 2;
        }

        return min(children - 1, money / 7);
    }
};