## =================================================================
##
## File: exercise02.py
## Author(s): Javier Suarez Duran
##            Daniel Rodríguez Figueroa
## Description: This file contains the code that performs the sum of 
##				all prime numbers less than or equal to MAXIMUM. The 
##				time this implementation takes will be used as the 
##				basis to calculate the improvement obtained with 
##				parallel technologies.
##
## Copyright (c) 2022 by Tecnologico de Monterrey.
## All Rights Reserved. May be reproduced for any non-commercial
## purpose.
##
## =================================================================

from math import sqrt
import utils
import time

MAXIMUM = 1000000 ##1e6

## Place your code here
def isPrimeNumber(x) :
    if (x < 2) :
        return False
    for i in range(2, int(sqrt(x))) :
        if (x % i == 0) :
            return False
    return True

def sumPrimeNumbers(maximum) :
    acum = 0
    
    for i in range(maximum) :
        if (isPrimeNumber(i)) :
            acum += i
    
    return acum

if __name__ == "__main__":
    print("Starting...")
    startTime = endTime = ms = 0
    result = 0
    for i in range(utils.N):
        startTime = time.time() * 1000

        result = sumPrimeNumbers(MAXIMUM)

        endTime = time.time() * 1000

        ms = ms + (endTime - startTime)

    print("sum = ", result)
    print("avg time = ", (ms / utils.N), " ms")