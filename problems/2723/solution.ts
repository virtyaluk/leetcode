async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    const num1 = await promise1,
        num2 = await promise2;
    
    return num1 + num2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */