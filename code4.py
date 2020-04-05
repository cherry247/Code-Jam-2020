#code 4  python 3
import numpy as np
import sys
from itertools import combinations



def negationing(bits): return [
    '_' if b is '_' else
    '1' if b=='0' else '0'
    for b in bits
]

class qarr():
	#constructor
    def __init__(self, a):
        self.bits = ['_'] * a
        self.unkowns = list(range(a))
        self.read(10)
        self.running()
	#readthebits
	
	
	def readthebits(self, i):
        print(i, flush=True)
        return input()
		
	def ti(self):
        c= list(set(range(B)) - set(self.unkowns))
        maxi = len(set(map(tuple, self.states)))
        for index in combinations(c, 2):
            num = len(set(tuple(np.take(state, index))for state in self.states))
                
            
            if num == maxi: return index


    def read(self, n):
        for _ in range(n):
            i = self.unkowns.pop()
            self.bits[i] = self.readthebits(i+1)
            self.unkowns = self.unkowns[::-1]
        self.changes()

    

    def changes(self):
        self.bc  = negation(self.bits)
        self.bcr = self.bc[::-1]
        self.br  = negation(self.bcr)
        self.states = [self.bits, self.bc, self.bcr, self.br]

    
    def des(self):        
        test_idx = self.ti()
        test = [self.readthebits(i+1) for i in test_idx]
               
        self.bits = next(state for state in self.states if test == list(np.take(state, test_idx)))
       

    def running(self):
        while True:
            self.des()
            try: self.read(8)
            except IndexError: break
   

T, B = map(int, input().split())
print('B:', B, file=sys.stderr)
for _ in range(T):
    array = qarr(B)
    print('guess:', ''.join(array.bits), file=sys.stderr)
    print(''.join(array.bits), flush=True)
    if input() == 'N': sys.exit()

