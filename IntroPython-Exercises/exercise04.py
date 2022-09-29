## =================================================================
##
## File: exercise04.py
## Author(s): Javier Suarez Duran
##            Daniel Rodríguez Figueroa
## Description: This file implements the PI approximation using the
##				series proposed by Euler.
##				pi = sqrt ( 6 * sumatoria(i = 1-N) (1 / i^2) )
##				The time this implementation takes will be used as
##				the basis to calculate the improvement obtained with
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

SIZE = 100000000 ##1e8

def pi_WithEuler(array) :
    sum = 0

    for i in range(1, len(array)) :
        sum = sum + (1 / i ** 2)
    
    pi = sqrt(6 * sum)

    return pi

if __name__ == "__main__":
    array = [0] * SIZE

    utils.fillArray(array)
    utils.displayArray("array", array)

    print("Starting...")
    startTime = endTime = ms = 0
    result = 0
    for i in range(utils.N):
        startTime = time.time() * 1000

        result = pi_WithEuler(array)

        endTime = time.time() * 1000

        ms = ms + (endTime - startTime)

    print("result = ", result)
    print("avg time = ", (ms / utils.N), " ms")