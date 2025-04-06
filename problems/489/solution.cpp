/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

const int DIRS[5] = {-1, 0, 1, 0, -1};

class Solution {
private:
    unordered_set<int> visited;

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(Robot& robot, int x, int y, int d) {
        visited.insert(x * 2000 + y);
        robot.clean();

        for (int i = 0; i < 4; i++) {
            int di = (d + i) % 4,
                nextX = x + DIRS[di],
                nextY = y + DIRS[di + 1];
            
            if (not visited.count(nextX * 2000 + nextY) and robot.move()) {
                backtrack(robot, nextX, nextY, di);
                goBack(robot);
            }

            robot.turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
};