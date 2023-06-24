interface DictVal {
    val: number;
    timer: any;
}

class TimeLimitedCache {
    dict: Map<number, DictVal>;

    constructor() {
        this.dict = new Map();
    }

    set(key: number, value: number, duration: number): boolean {
        clearTimeout(this.dict.get(key)?.timer);
        const ans = this.dict.has(key);
        this.dict.set(key, {val: value, timer: setTimeout(() => this.dict.delete(key), duration)});
        
        return ans;
    }

    get(key: number): number {
        if (this.dict.has(key)) {
            return this.dict.get(key).val;
        }
        
        return -1;
    }

	count(): number {
        return this.dict.size;
    }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */