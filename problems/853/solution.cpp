class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0;
        double slowest = 0.0;
        map<int, double> cars;
        
        for (int i = 0; i < size(position); i++) {
            cars[-position[i]] = (double) (target - position[i]) / speed[i];
        }
        
        for (auto [ignore, hoursToTarget]: cars) {
            if (hoursToTarget > slowest) {
                ans++;
                slowest = hoursToTarget;
            } 
        }
        
        return ans;
    }
    
    int carFleet1(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0, n = size(position);
        vector<pair<int, double>> cars;
        
        for (int i = 0; i < n; i++) {
            cars.push_back({
                position[i],
                (double) (target - position[i]) / speed[i]
            });
        }
        
        sort(begin(cars), end(cars), greater());
        
        double cur = 0.0;
        
        for (auto [pos, hoursToTarget]: cars) {
            if (hoursToTarget > cur) {
                ans++;
                cur = hoursToTarget;
            }
        }
        
        return ans;
    }
};

/*
10: 2
8: 4
0: 1
5: 1
3: 3

0: 1 -> 11
3: 3 -> 3
5: 1 -> 7
8: 4 -> 1
10: 2 -> 1


*/