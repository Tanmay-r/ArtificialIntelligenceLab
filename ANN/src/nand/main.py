from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..nand.nand import *
import numpy as np
import math

M = 0.1
eta = 0.9
errorThresh = 0.2

inputArray = buildInput(2)
outputArray = f_NAND(inputArray)
layer = np.array([3, 3, 2])

w = initializeW(layer, 1)
print "Estimating weights..."
backpropagation(layer, inputArray, outputArray, w, eta, M, errorThresh)
print "Weights: "
print w

flag = 'Y'
while(flag == 'Y'):
	x = []
	x.append(-1)
	x.append(input('Please enter the value of A: '))
	x.append(input('Please enter the value of B: '))
	inputX = np.array(x)
	outputs = feedForward(w, inputX, layer)
	if(outputs[layer[layer.shape[0] - 1] - 1] < 0.5):
		print "NAND(A, B) = ", 0
	else:
		print "NAND(A, B) = ", 1
	flag = raw_input('Want to check another? (Y/N) : ')