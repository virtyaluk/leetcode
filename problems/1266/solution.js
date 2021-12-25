/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let d = 0;
    let [x, y] = points[0];
    
    for (let i = 1; i < points.length; i++) {
        const [cx, cy] = points[i];
        
        d += Math.max(Math.abs(cx - x), Math.abs(cy - y));
        x = cx;
        y = cy;
    }
    
    return d;
};