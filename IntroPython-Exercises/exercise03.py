## =================================================================
##
## File: exercise03.py
## Author(s): Javier Suarez Duran
##            Daniel Rodríguez Figueroa
## Description: This file contains the code that implements the
##				enumeration sort algorithm. The time this implementation
##				takes ill be used as the basis to calculate the
##				improvement obtained with parallel technologies.
##
## Copyright (c) 2022 by Tecnologico de Monterrey.
## All Rights Reserved. May be reproduced for any non-commercial
## purpose.
##
## =================================================================

import utils
import time

SIZE = 10000 ##1e5

def swap(array, i, j):
    aux = array[i]
    array[i] = array[j]
    array[j] = aux 

def enumerationSort(array) :
    aux = array.copy()
    for i in range(len(aux) - 1, -1, -1) :
        for j in range(0, i) :
            if ((aux[i] < aux[j]) or ((aux[i] == aux[j]) and [i < j])) :
                swap(aux, j, i)

    return aux

if __name__ == "__main__":
    array = [0] * SIZE

    utils.randomArray(array)
    utils.displayArray("before", array)

    print("Starting...")
    startTime = endTime = ms = 0
    for i in range(utils.N):
        startTime = time.time() * 1000

        result = enumerationSort(array)

        endTime = time.time() * 1000

        ms = ms + (endTime - startTime)

    utils.displayArray("after", result)
    print("avg time = ", (ms / utils.N), " ms")