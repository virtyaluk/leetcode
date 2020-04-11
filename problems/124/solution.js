/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    let totalSum = -Infinity;
    
    var maxPath = function(node){
		// Return 0 if no node available
        if(!node) return 0;

		// Calculate the left and right sub tree path
        let leftMaxPath = Math.max(maxPath(node.left),0);
        let rightMaxPath = Math.max(maxPath(node.right),0);

		// Sum the above path value to the node value to calculate the maximum
        let score = node.val + leftMaxPath + rightMaxPath;
        totalSum = Math.max(score, totalSum) 

        return Math.max(leftMaxPath + node.val, rightMaxPath + node.val, 0);
    
    }
    
    maxPath(root)
    
    return totalSum;
};