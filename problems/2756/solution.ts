type QueryMultiple = (keys: string[]) => Promise<string[]>

class QueryBatcher {
    private queryMultiple: QueryMultiple;
    private t: number;
    private isAvailable: boolean;
    private stashed: Array<any>;
    
    constructor(queryMultiple: QueryMultiple, t: number) {
        this.queryMultiple = queryMultiple;
        this.t = t;
        this.isAvailable = true;
        this.stashed = [];
    }
    
    async getValue(key: string): Promise<string> {
        return new Promise((resolve) => {
            if (this.isAvailable) {
                this.isAvailable = false;
                this.queryMultiple([key]).then(results => resolve(results[0]));
                this.cooldown();
                
                return;
            }
            
            this.stashed.push({ key, resolve });
        });
    }
    
    private cooldown(): void {
        setTimeout(() => {
            if (this.stashed.length === 0) {
                this.isAvailable = true;
                
                return;
            }

            const keysToQuery = this.stashed.map(item => item.key),
                resolvers = this.stashed.map(item => item.resolve);

            this.stashed = [];

            this.queryMultiple(keysToQuery).then(results => {
                resolvers.forEach((resolve, idx) => resolve(results[idx]));
            });

            this.cooldown();
        }, this.t);
    }
};

/**
 * async function queryMultiple(keys) { 
 *   return keys.map(key => key + '!');
 * }
 *
 * const batcher = new QueryBatcher(queryMultiple, 100);
 * batcher.getValue('a').then(console.log); // resolves "a!" at t=0ms 
 * batcher.getValue('b').then(console.log); // resolves "b!" at t=100ms 
 * batcher.getValue('c').then(console.log); // resolves "c!" at t=100ms 
 */