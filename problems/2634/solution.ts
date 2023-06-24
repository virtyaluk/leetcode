function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let ans = [];
    
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {
            ans.push(arr[i]);
        }
    }
    
    return ans;
};