/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if (!node) {
        return null;
    }
    
    return helper(node, new Map());
};

function helper(node, m) {
    if (m.has(node)) {
        return m.get(node);
    }
    
    const cloned = new Node(node.val);
    m.set(node, cloned);
    
    for (const neighbor of node.neighbors) {
        cloned.neighbors.push(helper(neighbor, m));
    }
    
    return cloned;
}