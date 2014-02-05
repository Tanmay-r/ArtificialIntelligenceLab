import backpropagationv3
import numpy as np
import math
import buildInput
import functions

M = 0.1
inputArray = buildInput.buildInput(5)
outputArray = functions.f_Parity(inputArray)
layer = np.array([6, 6, 2])
wt = backpropagationv3.initializeW(layer, 1)
backpropagationv3.backpropagation(layer, inputArray, outputArray, wt ,0.9 , M)