class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int j = 0;
        
        sort(begin(boxes), end(boxes));
        
        for (int i = 1; i < warehouse.size(); i++) {
            warehouse[i] = min(warehouse[i - 1], warehouse[i]);
        }
        
        for (int i = warehouse.size() - 1; i >= 0; i--) {
            if (j < boxes.size() and boxes[j] <= warehouse[i]) {
                j++;
            }
        }
        
        return j;
    }
    
    int maxBoxesInWarehouse2(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> minHeight(warehouse.size());
        int j = 0;
        
        sort(begin(boxes), end(boxes));
        
        minHeight[0] = warehouse[0];
        
        for (int i = 1; i < warehouse.size(); i++) {
            minHeight[i] = min(minHeight[i - 1], warehouse[i]);
        }
        
        for (int i = warehouse.size() - 1; i >= 0; i--) {
            if (j < boxes.size() and boxes[j] <= warehouse[i] and boxes[j] <= minHeight[i]) {
                j++;
            }
        }
        
        return j;
    }
    
    int maxBoxesInWarehouse1(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> minHeight(warehouse.size());
        priority_queue<int, vector<int>, greater<>> pq;
        // sort(begin(boxes), end(boxes));
        
        for (const int& box: boxes) {
            pq.push(box);
        }
        
        minHeight[0] = warehouse[0];
        
        for (int i = 1; i < warehouse.size(); i++) {
            minHeight[i] = min(minHeight[i - 1], warehouse[i]);
        }
        
        for (int i = warehouse.size() - 1; i >= 0; i--) {
            if (not pq.empty() and pq.top() <= warehouse[i] and pq.top() <= minHeight[i]) {
                pq.pop();
            }
        }
        
        return boxes.size() - pq.size();
    }
};