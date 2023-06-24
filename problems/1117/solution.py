from threading import Lock

class H2O:
    def __init__(self):
        self.h = Lock()
        self.o = Lock()
        self.count = 0;
        self.o.acquire()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h.acquire()
        self.count += 1
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        
        if self.count == 2:
            self.count = 0
            self.o.release()
        else:
            self.h.release()


    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.o.acquire()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.h.release()