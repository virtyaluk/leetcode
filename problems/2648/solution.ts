function* fibGenerator(): Generator<number, any, number> {
    let ar = [0, 1],
        idx = 0;

    while (ar.length <= 50) {
        const len = ar.length;
        ar.push(ar[len - 1] + ar[len - 2]);
    }
    
    while (true) {
        yield ar[idx++];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */