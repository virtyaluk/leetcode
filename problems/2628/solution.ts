function areDeeplyEqual(o1: any, o2: any): boolean {
    const helper = (key, val) => {
        if (val && typeof val === 'object' && !Array.isArray(val)) {
            return Object.fromEntries(Object.entries(val).sort());
        }
        
        return val;
    };
    
    return JSON.stringify(o1, helper) === JSON.stringify(o2, helper);
};