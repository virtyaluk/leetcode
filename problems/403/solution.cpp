class Solution {
public:
    bool canCross1(vector<int>& stones) {
        for (int i = 0; i < size(stones) - 1; i++) {
            if (stones[i + 1] - stones[i] > i + 1) {
                return false;
            }
        }
        
        unordered_set<int> ss(begin(stones), end(stones));
        
        return recursive(stones, ss, 1, 1);
    }
    
    bool recursive(vector<int>& stones, unordered_set<int>& ss, int stone, int step) {
        if (stone == stones.back()) {
            return true;
        }
        
        if (not ss.count(stone)) {
            return false;
        }
        
        int next = stone + step;
        
        return recursive(stones, ss, next + 1, step + 1) or recursive(stones, ss, next, step) or (step > 1 and recursive(stones, ss, next - 1, step - 1));
    }
    
    bool canCross(vector<int>& stones) {
        int n = size(stones);
        unordered_map<int, unordered_set<int>> steps;
        
        for (const int& stone: stones) {
            steps[stone] = {};
        }
        
        steps[0].insert(0);
        
        for (const int& stone: stones) { // 0; 1; 3;
            for (int k: steps[stone]) { // 0; 1; 2
                for (int step = k - 1; step <= k + 1; step++) { // -1, 0, 1; 0, 1, 2; 1, 2, 3;
                    if (step > 0 and steps.count(stone + step)) {
                        steps[stone + step].insert(step); // 1: 1; 3: 2;
                    }
                }
            }
        }
        
        return not empty(steps[stones.back()]);
    }
};
