class Trip {
public:
    int pas, loc;
    Trip(int _pas, int _loc) {
        pas = _pas;
        loc = _loc;
    }
};

class MyComparator {
public:
    bool operator() (const Trip& left, const Trip& right) {
        if (left.loc == right.loc) {
            return left.pas > right.pas;
        }
        
        return left.loc > right.loc;
    }
};

class Solution {
public:
    bool carPooling1(vector<vector<int>>& trips, int capacity) {
        vector<int> sum(1001);
        
        for (auto trip: trips) {
            sum[trip[1]] += trip[0];
            sum[trip[2]] -= trip[0];
        }
        
        int curCapacity = 0;
        
        for (int i = 0; i < sum.size(); i++) {
            curCapacity += sum[i];
            
            if (curCapacity > capacity) {
                return false;
            }
        }
        
        return true;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<Trip, vector<Trip>, MyComparator> heap;
        int curCap = 0;
        
        for (vector<int> trip: trips) {
            heap.push(Trip(trip[0], trip[1]));
            heap.push(Trip(-trip[0], trip[2]));
        }
        
        while (!heap.empty()) {
            curCap += heap.top().pas;
            heap.pop();
            
            if (curCap > capacity) {
                return false;
            }
        }
        
        return true;
    }
};