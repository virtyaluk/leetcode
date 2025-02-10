class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = size(energyDrinkA);
        vector<long long> dpa(n),
            dpb(n);
        
        dpa.front() = energyDrinkA.front();
        dpb.front() = energyDrinkB.front();
        
        for (int i = 1; i < n; i++) {
            dpa[i] = energyDrinkA[i] + max(dpa[i - 1], i > 1 ? dpb[i - 2] : 0);
            dpb[i] = energyDrinkB[i] + max(dpb[i - 1], i > 1 ? dpa[i - 2] : 0);
        }
        
        return max(dpa.back(), dpb.back());
    }
};