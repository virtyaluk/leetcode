function createInfiniteObject(): Record<string, () => string> {
    return new Proxy({}, {
        get: (_, prop) => () =>  prop
    });
};

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */