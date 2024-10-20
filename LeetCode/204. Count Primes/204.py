class Solution:

    def NewInit(self, Temporary: int) -> None:
        self.primes = [True for _ in range(Temporary)]
        self.qtd = Temporary
        self.Resolve = 0


    def RemoveMultiple(self, multiple: int) -> None:
        for i in range(multiple*2 , self.qtd, +multiple):
            self.primes[i] = False

    def countPrimes(self, n: int) -> int:
        self.NewInit(n)
        for i in range(2, n): 
            if self.primes[i]:
                self.RemoveMultiple(i)
                self.Resolve+=1
        
        return self.Resolve


