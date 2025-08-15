class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        if ((mainTank - 1) / 4 < additionalTank) {
            return (((mainTank - 1) / 4) + mainTank) * 10;
        }

        return (additionalTank + mainTank) * 10;
    }
};