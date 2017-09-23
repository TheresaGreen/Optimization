
#Define a function to use 

import math as m
import numpy as np

def f(num):
    return  (8*np.e**(1-num))+(7*np.log(num))

# define starting intervals 
Left = 1
Right = 2
Accuracy = .23

###########################dont need to edit beyond here
##get your inital set up
TotalLength = Right - Left
Gratio = (3 - m.sqrt(5))/2
Gamma = Gratio * TotalLength


LeftEnd = Left
RightEnd = Right

MidLeft = LeftEnd + Gamma
MidRight = RightEnd - Gamma

Length = TotalLength

print('Initial Interval')
print('[',Left,',', Right, ']', '\n')


n=1
while ((1-Gratio)**(n-1) > (Accuracy / TotalLength)):
    print('Iteration: ', n)
    print ('f(MidLeft) , f(MidRight) ', f(MidLeft), ',', f(MidRight) )
    # define a new lemgth and new gamma
    Length = Length - Gamma
    Gamma = Gratio * (Length)
    
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
    
    print('Interval:   [',LeftEnd,',', RightEnd, ']')
    print('Midpoints: ', MidLeft, ',', MidRight,'\n')

    n = n + 1