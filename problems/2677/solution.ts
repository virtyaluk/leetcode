function chunk(arr: any[], size: number): any[][] {
    const ans = [];
    let idx = 0;
    
    while (idx < arr.length) {
        ans.push(arr.slice(idx, idx + size));
        idx += size;
    }
    
    return ans;
};
