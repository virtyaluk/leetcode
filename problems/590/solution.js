/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var postorder = function(root) {
    let postorder = [];
    let stack = [];
    
    if (!root) {
        return postorder;
    }
    
    stack.push(root);
    
    while (stack.length > 0) {
        const node = stack.pop();
        
        if (!node) {
            continue
        }
        
        const n = node.children && node.children.length || 0;
        
        postorder.unshift(node.val);
        
        for (let i = 0; i < n; i++) {
            stack.push(node.children[i]);
        }
    }
    
    return postorder;//.reverse();
};