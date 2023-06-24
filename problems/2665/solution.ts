type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let counter = init;
    
    return {
        increment: () => {
            counter++;
            
            return counter;
        },
        
        decrement: () => {
            counter--;
            
            return counter;
        },
        
        reset: () => {
            counter = init;
            
            return counter;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */