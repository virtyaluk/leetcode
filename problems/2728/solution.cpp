/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        int ans = 0;
        
        for (int i = 0; i < k; i++) {
            street->closeDoor();
            street->moveLeft();
        }
        
        while (not street->isDoorOpen()) {
            street->openDoor();
            street->moveLeft();
            ans++;
        }
        
        return ans;
    }
};