type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    subscribers: any = {};
    
  subscribe(eventName: string, callback: Callback): Subscription {
      
      if (!(eventName in this.subscribers)) {
          this.subscribers[eventName] = [];
      }
      
      this.subscribers[eventName].push(callback);

    return {
      unsubscribe: () => {
        this.subscribers[eventName].splice(this.subscribers[eventName].indexOf(callback));
      }
    };
  }

  emit(eventName: string, args: any[] = []): any {
      if (!(eventName in this.subscribers)) {
          return [];
      }
      
    let ans = [];
      
      for (let cb of this.subscribers[eventName]) {
          ans.push(cb(...args));
      }
      
      return ans;
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */