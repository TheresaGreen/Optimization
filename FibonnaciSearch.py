###fib

#Define a function to use 

import math as m
import numpy as np

def f(num):
    return (8*np.e**(1-num))+(7*np.log(num)) 

def fib(n):
    if n==0: return 1
    elif n==1: return 1
    else: return fib(n-2) + fib(n-1)

# define starting intervals 
Left = 1
Right = 2
Accuracy = .23
epsilon = .05

###########################dont need to edit beyond here
##get your inital set up

##Step 1 Find how many n we shall need!

TotalLength = Right - Left
N=0
while( (1/fib(N)) > (Accuracy/TotalLength )):
    N = N +1
    
print('Total Iterations: ', N, '\n')
##set initial gamma
ratio = 1 - (fib(N)/fib(N+1))
Gamma = ratio * TotalLength

LeftEnd = Left
RightEnd = Right

MidLeft = LeftEnd + Gamma
MidRight = RightEnd - Gamma

Length = TotalLength

print('Initial Interval')
print('[',Left,',', Right, ']')
print('Starting Mid points: ', MidLeft, ',', MidRight, '\n')


iteration = 1
while (iteration < N):
    print('Iteration: ', iteration )
    
    # define a new lemgth and new gamma
    Length = Length - Gamma
    ratio = 1- (fib(N-iteration)/fib(N-iteration+1))
    if ((iteration) == (N -1)):
        ratio = ratio + epsilon
    Gamma = ratio * Length
    
    print('ratio: ' , ratio)
    print('Midpoints: ', MidLeft, ',', MidRight,)
    print ('f(MidLeft) , f(MidRight) ', f(MidLeft), ',', f(MidRight) )
  
    if (f(MidLeft) < f(MidRight)):
        # new interval [LeftEnd, MidRight]
        RightEnd = MidRight
        MidRight = MidLeft
        MidLeft=LeftEnd + Gamma
        
    elif (f(MidLeft) > f(MidRight)):
        # new interval [MidLeft, RightEnd]
        LeftEnd = MidLeft
        MidLeft = MidRight
        MidRight = RightEnd-Gamma
    
    print('New Interval:   [',LeftEnd,',', RightEnd, ']', '\n')

    iteration = iteration +1
