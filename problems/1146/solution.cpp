class SnapshotArray {
private:
    int snapId = 0;
    unordered_map<int, map<int, int>> arr;

public:
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        arr[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id);
        
        return begin(arr[index]) == it ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */