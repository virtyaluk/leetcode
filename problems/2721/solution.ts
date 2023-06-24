async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    let promises = functions.map(fn => fn().catch(er => Promise.reject(er)));

    return Promise.all(promises);
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */