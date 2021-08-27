class ExamRoom {
private:
    set<int> seats;
    int n;

public:
    ExamRoom(int n): n{n} {}
    
    int seat() {
        int dist = 0,
            cur = 0;
        
        if (not empty(seats)) {
            auto it = begin(seats);
            dist = *it;
            
            if (not dist) {
                it++;
            }
            
            while (it != end(seats)) {
                int nextDist = (*it - *prev(it)) / 2;
                
                if (dist < nextDist) {
                    dist = nextDist;
                    cur = *prev(it) + dist;
                }
                
                it++;
            }
            
            if (dist < n - 1 - *rbegin(seats)) {
                cur = n -1;
            }
        }
        
        seats.insert(cur);
        
        return cur;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */