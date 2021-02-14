/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    let points = [];
    
    for (let i = 0; i < ops.length; i++) {
        switch (ops[i]) {
            case "+": {
                points.push(points[points.length - 1] + points[points.length - 2]);
                
                break;
            }
                
            case "C": {
                points.pop();
                
                break;
            }
                
            case "D": {
                points.push(points[points.length - 1] * 2);
                
                break;
            }
                
            default: {
                points.push(parseInt(ops[i]));
                
                break;
            }
        }
    }
    
    return points.reduce((cv, ac) => cv + ac, 0);
};