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
var preorder = function(root) {
    let preorder = [],
        stack = [];
    
    if (!root) {
        return preorder;
    }
    
    stack.push(root);
    
    while (stack.length > 0) {
        const node = stack.pop();
        
        if (!node) {
            continue;
        }
        
        const n = node.children && node.children.length || 0;
        
        preorder.push(node.val);
        
        for (let i = n; i >= 0; i--) {
            stack.push(node.children[i]);
        }
    }
    
    return preorder;
};