type F = (x: number) => number;

function compose(functions: F[]): F {
    return function(x: number): number {
        while (functions.length) {
            x = functions.pop()(x);
        }
        
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */