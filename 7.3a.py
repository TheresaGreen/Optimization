#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 14:59:44 2017

@author: terri
"""

import numpy as np
import matplotlib.pyplot as plt

def f(num):
    return  (8*np.e**(1-num))+(7*np.log(num))
x = np.linspace(1,2, num=100)

plt.plot(x, f(x ))
plt.show()
 
 