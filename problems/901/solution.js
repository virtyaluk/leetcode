
var StockSpanner = function() {
    this.index = -1;
    this.stack = [];
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function(price) {
    let ans = 0;
    
    this.index++;
    
    while (this.stack.length > 0 && this.stack[this.stack.length - 1][1] <= price) {
        this.stack.pop();
    }
    
    if (this.stack.length > 0) {
        ans = this.index - this.stack[this.stack.length - 1][0];
    } else {
        ans = this.index + 1;
    }
    
    this.stack.push([this.index, price]);
    
    return ans;
};

/** 
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */