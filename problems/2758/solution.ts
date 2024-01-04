declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function(){
    this.setDate(this.getDate() + 1);
    
    return this.getFullYear() + '-' + (this.getMonth() + 1).toString().padStart(2, 0) + '-' + this.getDate().toString().padStart(2, 0);
}

/**
 * const date = new Date("2014-06-20");
 * date.nextDay(); // "2014-06-21"
 */