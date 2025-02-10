class NumberContainers {
private:
    unordered_map<int, int> um1;
    unordered_map<int, set<int>> um2;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (um1.count(index)) {
            um2[um1[index]].erase(index);
        }

        um1[index] = number;
        um2[number].insert(index);
    }
    
    int find(int number) {
        if (not um2.count(number) or empty(um2[number])) {
            return -1;
        }

        return *begin(um2[number]);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */