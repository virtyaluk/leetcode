type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(a: any): ToBeOrNotToBe {
    return {
        toBe: (b) => {
            if (a === b) {
                return true;
            }
            
            throw new Error('Not Equal');
        },
        notToBe: (b) => {
            if (a !== b) {
                return true;
            }
            
            throw new Error('Equal');
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */