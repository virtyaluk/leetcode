function join(arr1: any[], arr2: any[]): any[] {
    let map = {},
        arrs = [...arr1, ...arr2].map((e) => map[e.id] = {...map[e.id], ...e})
    
    return [...Object.values(map)]
};