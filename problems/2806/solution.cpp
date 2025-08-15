class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int num = (purchaseAmount / 10) * 10;

        if (purchaseAmount % 10 >= 5) {
            num += 10;
        }

        return 100 - num;
    }
};