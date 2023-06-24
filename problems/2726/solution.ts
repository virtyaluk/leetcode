class Calculator {
    num: number = 0;
  constructor(value : number) {
    this.num = value;
  }
    
  add(value : number) : Calculator {
      this.num += value;
    return this;
  }
    
  subtract(value : number) : Calculator {
      this.num -= value;
     return this;
  }
    
  multiply(value : number) : Calculator {
      this.num *= value;
     return this;
  }

  divide(value : number) : Calculator {
      if (value === 0) {
          throw new Error('Division by zero is not allowed');
      }
      
      this.num /= value;
     return this;
  }
    
  power(value : number) : Calculator {
      this.num **= value;
     return this;
  }

  getResult() : number {
   return this.num;
  }
}