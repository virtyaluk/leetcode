function isEmpty(obj: Record<string, any> | any[]): boolean {
    if (Array.isArray(obj)) {
        return !obj.length;
    }
    
    return !Object.keys(obj).length;
};