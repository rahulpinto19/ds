class Solution(object):
    dict = {
        0:0,
        1:1
    }
    def fib(self, n):
        
        if n in self.dict:
            return self.dict[n]
        
        self.dict[n] = self.fib(n-1) + self.fib(n-2)
        return self.dict[n]
    
    