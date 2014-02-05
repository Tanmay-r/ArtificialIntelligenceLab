import backpropagationv3
import numpy as np
import math
import buildInput
import functions

inputArray = buildInput.buildInput(2)
outputArray = functions.f_XOR(inputArray)
layer = np.array([3, 3, 2])
wt = backpropagationv3.initializeW(layer, 1)

M = 0.8
for j in range(1,11):
	tempwt = backpropagationv3.initializeW(layer, 0)
	w = backpropagationv3.addDeltaW(tempwt, wt , layer)
	backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,j/10.0 , M)
	print "!!!"
print "*****************"
