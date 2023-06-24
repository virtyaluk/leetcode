function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let ans = [];
    
    for (let i = 0; i < arr.length; i++) {
        ans.push(fn(arr[i], i));
    }
    
    return ans;
};