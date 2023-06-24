declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    if (this.length !== rowsCount * colsCount) {
        return [];
    }

    const result: number[][] = [...new Array(rowsCount)].map(_ => new Array(colsCount));

    let increment = 1;
    let row = 0, col = 0;
    for (let k = 0; k < this.length; k++) {
        result[row][col] = this[k];
        row += increment;
        if (row === rowsCount || row === -1) {
            increment *= -1;
            row += increment;
            col++;
        }
    }

    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */