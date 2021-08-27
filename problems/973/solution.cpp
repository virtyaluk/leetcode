class Solution {
public:
//     static inline int getDist(const vector<int>& point) {
//         return point[0] * point[0] + point[1] * point[1];
//     }
    
//     static inline bool cmpDist(const vector<int>& lhs, const vector<int>& rhs) {
//         return getDist(lhs) < getDist(rhs);
//     }
    
//     // standard Quicksort(Lomuto) partition
//     int partition(vector<vector<int>>& points, int lo, int hi) {
//         vector<int> pivot = points[hi];
//         int startIdx = lo;
        
//         for (int i = lo; i < hi; i++) {
//             if (cmpDist(points[i], pivot)) {
//                 swap(points[i], points[startIdx]);
//                 startIdx++;
//             }
//         }
        
//         swap(points[startIdx], points[hi]);
        
//         return startIdx;
//     }
    
//     void quickselect(vector<vector<int>>& points, int lo, int hi, int k) {
//         while (lo <= hi) {
//             int mid = partition(points, lo, hi);
            
//             if (mid == k) {
//                 return;
//             } else if (mid < k) {
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }
//     }
    
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         quickselect(points, 0, size(points) - 1, k);
        
//         return {begin(points), begin(points) + k};
//     }
    
//     vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
//         nth_element(begin(points), begin(points) + k, end(points), cmpDist);
        
//         return {begin(points), begin(points) + k};
//     }
    
//     vector<vector<int>> kClosest1(vector<vector<int>>& points, int k) {
//         vector<vector<int>> ans;
//         auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
//             double lhsDist = sqrt(pow(lhs[0], 2) + pow(lhs[1], 2)),
//                 rhsDist = sqrt(pow(rhs[0], 2) + pow(rhs[1], 2));
            
//             return lhsDist < rhsDist;
//         };
//         priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
//         for (const vector<int>& point: points) {
//             pq.push(point);
            
//             if (size(pq) > k) {
//                 pq.pop();
//             }
//         }
        
//         while (not empty(pq)) {
//             ans.push_back(pq.top());
//             pq.pop();
//         }
        
//         return ans;
//     }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            distances.push_back(euclideanDistance(points[i]));
            high = max(high, distances[i]);
            remaining.push_back(i);
        }
                
        // Perform a binary search of the distances
        // to find the k closest points
        vector<int> closest;
        while (k) {
            double mid = (low + high) / 2;
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int> &closer = result[0], &farther = result[1];
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining.swap(closer);
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        vector<vector<int>> answer;
        for (int index : closest)
            answer.push_back(points[index]);
        return answer;
    }
    
private:
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances, 

double mid) {
        // Split the distances around the midpoint
        // and return them in separate vectors
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for (int index : remaining) {
            if (distances[index] <= mid) {
                closer.push_back(index);
            } else {
                farther.push_back(index);
            }
        }
        return result;
    } 
    
    double euclideanDistance(vector<int>& point) {
        // Calculate and return the Euclidean distance
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};